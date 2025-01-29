import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class LiteralTable {
    String value;
    int address;
}

class SymbolTable {
    String symbol;
    int address;
    int len;
}

class IntermediateCode {
    int location;
    HashMap<String, String> InstructionInfo;
    HashMap<String, String> OperandInfo;
    HashMap<String,String> RegisterTable;

    IntermediateCode() {
        InstructionInfo = new HashMap<>();
        OperandInfo = new HashMap<>();
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(this.getClass().getSimpleName() + " { ");
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

class assignment1 {
    HashMap<String, String> AssemblerDirectives, ImperativeStatements;
    HashMap<String, String> SymbolTable;
    ArrayList<LiteralTable> Literals;
    ArrayList<SymbolTable> Symbols;

    assignment1() {
        Literals = new ArrayList<LiteralTable>();
        Symbols = new ArrayList<SymbolTable>();

        AssemblerDirectives = new HashMap<>();
        ImperativeStatements = new HashMap<>();

        AssemblerDirectives.put("START", "01");
        AssemblerDirectives.put("ORIGIN", "02");
        AssemblerDirectives.put("EQU", "03");
        AssemblerDirectives.put("LTORG", "04");
        AssemblerDirectives.put("END", "05");

        ImperativeStatements.put("STOP", "00");
        ImperativeStatements.put("ADD", "01");
        ImperativeStatements.put("SUB", "02");
        ImperativeStatements.put("MULT", "03");
        ImperativeStatements.put("MOVER", "04");
        ImperativeStatements.put("MOVEM", "05");
        ImperativeStatements.put("BC", "06");
    }

    ArrayList<IntermediateCode> GenerateObjectCode(String FilePath) {
        ArrayList<IntermediateCode> ic = new ArrayList<IntermediateCode>();
        int location_tracker = 0;
        try {
            File f = new File(FilePath);
            Scanner scan = new Scanner(f);
            while (scan.hasNextLine()) {
                String line = scan.nextLine();
                String []result = line.split(" ");
                IntermediateCode temp = new IntermediateCode();
                if (result[0].contains("START")) {
                    location_tracker = Integer.parseInt(result[1]);
                    temp.InstructionInfo.put("AD", AssemblerDirectives.get(result[0]));
                    ic.add(temp);
                    continue;
                }
                for (String a: result) {
                    System.out.println(a);
                    if (AssemblerDirectives.containsKey(a)) {
                        temp.location = location_tracker;
                        temp.InstructionInfo.put("AD", AssemblerDirectives.get(a));
                        ic.add(temp);
                    }
                    if (ImperativeStatements.containsKey(a)) {
                        temp.location = location_tracker;
                        temp.InstructionInfo.put("IS", ImperativeStatements.get(a));
                        ic.add(temp);
                    } else {
                        if (a.contains("=")) {
                            LiteralTable lit = new LiteralTable();
                            lit.address = location_tracker;
                            lit.value = a;
                            Literals.add(lit);
                            temp.OperandInfo.put("C", a);
                        } else {
                            SymbolTable sym = new SymbolTable();
                            sym.address = location_tracker;
                            sym.symbol = a;
                            Symbols.add(sym);
                            temp.OperandInfo.put("S", a);
                        }
                    }
                }
                location_tracker++;
            }
            scan.close();
        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return ic;
    }
}
