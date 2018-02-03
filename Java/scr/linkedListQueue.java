import java.io.PrintWriter;

public class linkedListQueue {
	listNode head;
	listNode tail;
	
	linkedListQueue() {
		head = new listNode();//dummy
		tail = head;
	}
	
	void addTail(listNode ln) {
		tail.next = ln;
		tail = ln;
	}
	
	listNode deleteHead() {
		listNode temp = null;
		if (!isEmpty()) {
			temp = new listNode(head.next.data);
			head.next = head.next.next;
		}
		if (head.next == null) {
			tail = head;
		}
		return temp;
	}
	
	boolean isEmpty() {
		if (head == tail) {
			return true;
		}
		return false;
	}
	
	void printQueue(PrintWriter outFile) {
		listNode traveler = head.next;
		while (traveler != null) {
			if (traveler.next == null) {
				outFile.print(traveler.data.trim());
			}
			else {
				outFile.print(traveler.data.trim() + ", ");
			}
			traveler = traveler.next;
		}
	}
}
