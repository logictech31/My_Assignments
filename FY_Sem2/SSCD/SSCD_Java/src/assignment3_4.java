import java.io.File;
import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

class ALA_t {
    String RelativeArg, ActualArg, macroName;
    int Index;
    ALA_t (String RelativeArg, String actualArg, int Index, String macroName) {
        this.RelativeArg = RelativeArg;
        this.ActualArg = actualArg;
        this.Index = Index;
        this.macroName = macroName;
    }
    public String toString() {
        StringBuilder result = new StringBuilder(" { ");
        Field[] fields = this.getClass().getDeclaredFields();
        for (Field field : fields) {
            try {
                field.setAccessible(true); // Allow access to private fields
                result.append(field.getName()).append(" = ").append(field.get(this)).append(", ");
            } catch (IllegalAccessException e) {
                result.append(field.getName()).append(" = ").append("ACCESS ERROR, ");
            }
        }
        if (result.length() > 2) {
            result.setLength(result.length() - 2); // Remove trailing comma and space
        }
        result.append(" }");
        return result.toString();
    }
}

class MNT_t {
    MNT_t(int mnt_idx, int mdt_idx) {
        this.mdt_index = mdt_idx;
        this.mnt_index = mnt_idx;
    }
    int mnt_index;
    int mdt_index;
    public String toString() {
        StringBuilder result = new StringBuilder( " { ");
        Field[] fields = this.getClass().getDeclaredFields();
        for (Field field : fields) {
            try {
                field.setAccessible(true); // Allow access to private fields
                result.append(field.getName()).append(" = ").append(field.get(this)).append(", ");
            } catch (IllegalAccessException e) {
                result.append(field.getName()).append(" = ").append("ACCESS ERROR, ");
            }
        }
        if (result.length() > 2) {
            result.setLength(result.length() - 2); // Remove trailing comma and space
        }
        result.append(" }");
        return result.toString();
    }
}

public class assignment3_4 {
    static int MDTC, MNTC;
    static HashMap<Integer, String> MDT = new HashMap<>();
    static HashMap<String, MNT_t> MNT = new HashMap<>();
    static int MDLC;
    static int ALA_Tracker;
    static HashMap<String, ALA_t> ALA = new HashMap<>();
    static int LastMEND = 0;
    static String Filename;
    assignment3_4() {
        Filename = "";
        MDTC = 1;
        MDLC = 0;
        MNTC = 1;
        ALA_Tracker = 1;
    }

    String ExpandMacroIfNecessary() throws Exception {
        File src = new File(Filename);
        StringBuilder builder = new StringBuilder();
        Scanner scan = new Scanner(src);

        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            --LastMEND;
            if (line.contains("MACRO")) {
                break;
            }
            builder.append(line).append(System.lineSeparator());
        }

        while (scan.hasNextLine() && LastMEND > 0) {
            --LastMEND;
            scan.nextLine();
        }

        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            String[] parts = line.split(" ");

            if (!MNT.containsKey(parts[0])) {
                builder.append(line).append(System.lineSeparator());
                continue;
            }

            Stack<Integer> macroIndex = new Stack<>();
            macroIndex.push(MNT.get(parts[0]).mdt_index+1);
            int mdt_expansion = MNT.get(parts[0]).mdt_index+1;
            for (int i = 1; i < parts.length; i ++) {
                String mdtline = MDT.get(MNT.get(parts[0]).mdt_index);
                String mdtparts[] = mdtline.split(" ");
                String key = "#" + mdtparts[i].replaceFirst("&ARG", "");
                ALA_t macroArg = ALA.get(key);
                macroArg.ActualArg = parts[i];
                ALA.put(key, macroArg);
            }
            do {
                String macro_def = MDT.get(mdt_expansion);
                String[] result = macro_def.split(" ");

                if (MNT.containsKey(result[0])) {
                    macroIndex.push(mdt_expansion + 1);
                    mdt_expansion = MNT.get(result[0]).mdt_index+1;
                    for (int i = 1; i < result.length; i ++) {
                        String mdtline = MDT.get(MNT.get(result[0]).mdt_index);
                        String mdtparts[] = mdtline.split(" ");
                        String key = "#" + mdtparts[i].replaceFirst("&ARG", "");
                        ALA_t macroArg = ALA.get(key);
                        if (ALA.containsKey(result[i])) {
                            macroArg.ActualArg = ALA.get(result[i]).ActualArg;
                        } else {
                            macroArg.ActualArg = result[i];
                        }
                        ALA.put(result[i], macroArg);
                    }
                    continue;
                }
                String modifiedLine = "";
                for (int i = 0; i < result.length; i ++) {
                    if (ALA.containsKey(result[i])) {
                        ALA_t temp = ALA.get(result[i]);
                        modifiedLine += temp.ActualArg + " ";
                    } else {
                        modifiedLine += result[i] + " ";
                    }
                }
                if (macro_def.contains("MEND")) {
                    if (!macroIndex.isEmpty()) {
                        mdt_expansion = macroIndex.pop();
                        continue;
                    } else {
                        break;
                    }
                }

                builder.append(modifiedLine).append(System.lineSeparator());
                mdt_expansion++;
            }while (!macroIndex.isEmpty());
        }

        scan.close();
        return builder.toString();
    }

    public static void Convert(String filename) throws Exception {
        Filename = filename;
        boolean NextLineIsMacroDefinition = false;
        Integer local_mdt_tracker = 0, local_mnt_tracker = 0;
        int mend_ignore_tracker = 0, line_tracker = 0;
        int local_ala_tracker = 0;
        HashMap<String, String> reverseALAMap = new HashMap<>();

        System.out.println("Starting macro detection!");
        File src = new File(Filename);
        Scanner scan = new Scanner(src);

        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            ++line_tracker;
            String[] parts = line.split(" ");

            if (line.contains("MACRO")) {
                NextLineIsMacroDefinition = true;
                ++MDLC;
                ++mend_ignore_tracker;
                continue;
            }

            if (MDLC > 0) {
//                if (MNT.containsKey(result[0])) {
//                    MNT_t temp = MNT.get(result[0]);
//                    int mdt_expansion = temp.mdt_index;
//                    System.out.println("mdt_expansion = " + mdt_expansion);
//                    while (true) {
//                        String macro_def = MDT.get(++mdt_expansion);
//                        if (macro_def.contains("MEND")) {
//                            break;
//                        }
//                        MDT.put(++local_mdt_tracker, macro_def);
//                    }
//                    continue;
//                }

                if (NextLineIsMacroDefinition) {
                    NextLineIsMacroDefinition = false;
                    MNT_t obj = new MNT_t(++local_mnt_tracker, ++local_mdt_tracker);
                    String macroName = parts[0];
                    for (int i = 1; i < parts.length; i++) {
                        String key = "#" + parts[i].replaceFirst("&ARG", "");
                        ALA.put(key, new ALA_t(parts[i], "", i, macroName));
                        reverseALAMap.put(parts[i], key);
                    }

                    MNT.put(macroName, obj);
                    MDT.put(local_mdt_tracker, line);
                    continue;
                }
                String modifiedLine = "";
                for (int i = 0; i < parts.length; i ++) {
                    modifiedLine += reverseALAMap.getOrDefault(parts[i], parts[i]) + " ";
                }
                MDT.put(++local_mdt_tracker, modifiedLine);
                if (line.contains("MEND") && mend_ignore_tracker < 2) {
                    --mend_ignore_tracker;
                }
                if (mend_ignore_tracker == 0) {
                    --MDLC;
                    LastMEND = line_tracker;
                }
            }
        }

        System.out.println("LastMEND = " + LastMEND);
        System.out.println("MDT: " + MDT + "\nMNT: " + MNT + "\nALA: " + ALA);
        scan.close();
    }
}
