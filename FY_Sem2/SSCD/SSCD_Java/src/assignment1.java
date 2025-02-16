import java.io.File;
import java.lang.reflect.Field;
import java.util.*;

class MetaOps {
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

class LiteralTable {
    String value;
    int address;
}

class SymbolTable extends MetaOps {
    long index;
    int address;
    int len;
}

class IntermediateCode extends MetaOps {
    int location;
    HashMap<String, String> InstructionInfo;
    HashMap<String, String> OperandInfo;

    IntermediateCode() {
        InstructionInfo = new HashMap<>();
        OperandInfo = new HashMap<>();
    }

}

class assignment1 extends MetaOps {
    HashMap<String, String> AssemblerDirectives, ImperativeStatements;
    ArrayList<LiteralTable> Literals;
    HashMap<String, SymbolTable> Symbols;
    HashMap<String, String> RegList;
    int start;

    assignment1() {
        Literals = new ArrayList<LiteralTable>();

        Symbols = new HashMap<>();
        AssemblerDirectives = new HashMap<>();
        ImperativeStatements = new HashMap<>();
        RegList = new HashMap<>();

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

        RegList.put("AREG", "01");
        RegList.put("BREG", "02");
        RegList.put("CREG", "03");
        RegList.put("DREG", "04");
    }

    void updateSymTableIfNecessary(String symbol, int location) {
        SymbolTable sym = new SymbolTable();
        sym.address = location;
        sym.len = 1;
        if (!Symbols.containsKey(symbol)) {
            Symbols.put(symbol, sym);
            int uuindex = UUID.randomUUID().hashCode();
            sym.index = (uuindex < 0) ? uuindex * -1 : uuindex;
        } else {
            SymbolTable temp = Symbols.get(symbol);
            temp.address = location;
            Symbols.put(symbol, temp);
        }
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
                    start = location_tracker;
                    temp.InstructionInfo.put("AD", AssemblerDirectives.get(result[0]));
                    ic.add(temp);
                    continue;
                }
                for (int i = 0; result.length > i; i ++) {
                    if (AssemblerDirectives.containsKey(result[i])) {
                        if (result[i].contains("ORIGIN")) {
                            location_tracker = Integer.parseInt(result[1]) -1;
                        }
                        temp.location = location_tracker;
                        temp.InstructionInfo.put("AD", AssemblerDirectives.get(result[i]));
                        ic.add(temp);
                        break;
                    }
                    if (ImperativeStatements.containsKey(result[i])) {
                        temp.location = location_tracker;
                        temp.InstructionInfo.put("IS", ImperativeStatements.get(result[i]));
                        ic.add(temp);
                    } else {
                            if (RegList.containsKey(result[i])) {
                                updateSymTableIfNecessary(result[i + 1], location_tracker);
                                temp.OperandInfo.put(RegList.get(result[i]), result[i+1]);
                                break;
                            } else {
                                updateSymTableIfNecessary(result[i], location_tracker);
                                temp.OperandInfo.put("S", result[i]);
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
