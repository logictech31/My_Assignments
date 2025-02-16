import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

class assignment2 extends assignment1 {

    public void ConvertObjectCodeToMachineCode(ArrayList<IntermediateCode> IC) {
        for (IntermediateCode code: IC) {
            if (code.InstructionInfo.containsKey("AD") || code.InstructionInfo.containsKey("DC")) {
                continue;
            }
            System.out.print(code.location + " ");
            System.out.print(code.OperandInfo.keySet() + " ");
            Collection<String> operands = code.OperandInfo.values();
            Iterator<String> iter = operands.iterator();
            while (iter.hasNext()) {
                String val = iter.next();
                SymbolTable temp = Symbols.get(val);
                System.out.print(temp.index + " ");
                System.out.print(temp.address + " ");
                System.out.print("(Symbol index of " + val + " is " + temp.index + ")");
            }
            System.out.println();
        }
    }
}
