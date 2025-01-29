import java.io.BufferedReader;
import java.util.ArrayList;


public class main {
    static void help() {
        System.out.println("Please pass the filename as argument");
    }
    public static void main(String []args) {
        assignment1 assign1 = new assignment1();
        if (args.length < 1) {
            help();
            return;
        }
        ArrayList<IntermediateCode> ic = assign1.GenerateObjectCode(args[0]);

        for (IntermediateCode i: ic) {
            System.out.println(i.toString());
        }
    }
}
