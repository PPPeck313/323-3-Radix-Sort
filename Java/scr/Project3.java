import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Project3 {
	public static void main(String[] args) {
		try {
			Scanner inFile = new Scanner(new FileReader(args[0]));
			PrintWriter outFile = new PrintWriter(args[1]);
			
			RadixSort rS = new RadixSort();
			linkedListStack Top = new linkedListStack();
			
			while (inFile.hasNext()) {
				String data = inFile.next();
				listNode newNode = new listNode(data);
				Top.push(newNode);
				if (data.length() > rS.longestStringLength) {
					rS.longestStringLength = data.length();
				}
			}
			inFile.close();
			Top.printStack();
			
			listNode node;
			char val;
			int hashIndex;
			
			rS.currentDigit = rS.longestStringLength - 1;
			while (!Top.isEmpty()) {
				node = Top.pop();
				rS.padString(node);
				
				val = rS.getVal(node);
				hashIndex = rS.hashIndex(val);
				rS.hashTable[rS.currentTable][hashIndex].addTail(node);
			}
			rS.printTable(outFile);
			
			rS.currentDigit--;
			while (rS.currentDigit >= 0) {
				if (rS.currentTable == 0) {
					rS.currentTable = 1;
					rS.previousTable = 0;
				}
				else {
					rS.currentTable = 0;
					rS.previousTable = 1;
				}
				
				for (rS.tableIndex = 0; rS.tableIndex < rS.tableSize; rS.tableIndex++) {
					while (rS.hashTable[rS.previousTable][rS.tableIndex].head.next != null) {
						node = rS.hashTable[rS.previousTable][rS.tableIndex].deleteHead();
						
						val = rS.getVal(node);
						hashIndex = rS.hashIndex(val);
						rS.hashTable[rS.currentTable][hashIndex].addTail(node);
					}
				}
				rS.printTable(outFile);
				rS.currentDigit--;
			}
			outFile.close();
		}
		
		catch (Exception e) {
			System.out.println(e);
		}
	}
}