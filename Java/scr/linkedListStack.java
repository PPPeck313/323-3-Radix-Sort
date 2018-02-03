public class linkedListStack {
	listNode top;
	
	linkedListStack() {
		top = null;
	}
	
	void push(listNode ln) {
		ln.next = top;
		top = ln;
	}
	
	listNode pop() {
		listNode pop = new listNode(top.data);
		top = top.next;
		return pop;
	}
	
	boolean isEmpty() {
		if (top == null) {
			return true;
		}
		return false;
	}
	
	void printStack() {
		listNode traveler = top;
		while (traveler != null) {
			System.out.println(traveler.data);
			traveler = traveler.next;
		}
	}
}
