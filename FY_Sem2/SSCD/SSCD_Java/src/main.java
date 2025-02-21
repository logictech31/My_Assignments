import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;


public class main {
    static void help() {
        System.out.println("Please pass the filename as argument");
    }
    public static void main(String []args) throws Exception {
        assignment3_4 obj1 = new assignment3_4();
        assignment2 obj = new assignment2();
        if (args.length < 1) {
            help();
            return;
        }
        obj1.Convert(args[0]);
        String expandedMacro = obj1.ExpandMacroIfNecessary();
        System.out.println("\n----------New Code----------\n" + expandedMacro + "\n--------------------\n");
        String expandedFileName = "C:\\Users\\Hrush\\OneDrive\\Documents\\GitHub\\My_Assignments\\FY_Sem2\\SSCD\\SSCD_Java\\codes\\macro_expanded.txt";
        FileWriter writeExpanded = new FileWriter(expandedFileName);
        writeExpanded.write(expandedMacro);
        writeExpanded.close();

        ArrayList<IntermediateCode> ic = obj.GenerateObjectCode(expandedFileName);

        for (IntermediateCode i: ic) {
            System.out.println(i.toString());
        }

        obj.ConvertObjectCodeToMachineCode(ic);
    }
}
