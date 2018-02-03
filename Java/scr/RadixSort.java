import java.io.PrintWriter;

public class RadixSort {
	int tableSize = 256;
	linkedListQueue[][] hashTable;
	int currentTable;
	int previousTable;
	int longestStringLength;
	int currentDigit;
	int tableIndex;
	
	RadixSort() {
		hashTable = new linkedListQueue[2][tableSize];
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j < tableSize; j++) {
				hashTable[i][j] = new linkedListQueue();
			}
		}
		currentTable = 0;
		previousTable = 0;
		longestStringLength = 0;
		currentDigit = 0;
		tableIndex = 0;
	}
	
	char getVal(listNode ln) {
		return ln.data.charAt(currentDigit);
	}
	
	int hashIndex(char c) {
		int toInt = (int) c;
		return toInt;
	}
	
	void printTable(PrintWriter outFile) {
		for (tableIndex = 0; tableIndex < tableSize; tableIndex++) {
			if (hashTable[currentTable][tableIndex].head.next != null) {
				outFile.print("Table " + "[" + currentTable + "]" + "[" + tableIndex + "]: ");
				hashTable[currentTable][tableIndex].printQueue(outFile);
				outFile.println();
			}
		}
		outFile.println();
	}
	
	void padString(listNode ln) {
		while (ln.data.length() < longestStringLength) {
			ln.data = " " + ln.data;
		}
	}
}
