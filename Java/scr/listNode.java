public class listNode {
	String data;
	listNode next;
	
	listNode() {
		data = null;
		next = null;
	}
	
	listNode(String d) {
		data = d;
		next = null;
	}
	
	listNode(String d, listNode n) {
		data = d;
		next = n;
	}
	
	String getData() {
		return data;
	}
	
	listNode getNext() {
		return next;
	}
	
	void setData(String d) {
		data = d;
	}
	
	void setNext(listNode n) {
		next = n;
	}
}
