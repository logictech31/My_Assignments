import java.io.BufferedReader;
import java.util.ArrayList;


public class main {
    static void help() {
        System.out.println("Please pass the filename as argument");
    }
    public static void main(String []args) {
        assignment2 obj = new assignment2();
        if (args.length < 1) {
            help();
            return;
        }
        ArrayList<IntermediateCode> ic = obj.GenerateObjectCode(args[0]);

        for (IntermediateCode i: ic) {
            System.out.println(i.toString());
        }

        obj.ConvertObjectCodeToMachineCode(ic);
    }
}
