package algorithm;


public class BinaryTree {
	//필드
	Node rootNode = null;

	public class Node{
		
		int data;
		Node left;
		Node right;
		
		public Node(int value) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
		
	}
	

	public void add(int value) {
		
		if(rootNode ==null) {
			rootNode = new Node(value);
			
		}
			
		Node parent = rootNode;
		Node current;
			
		while(true) {
			
			current = parent;
			
			if(parent.data> value) {
				
				parent = parent.left;
				
				if(parent ==null) {
					current.left = new Node(value);
					break;
				}
		
			}else {
				
				parent = parent.right;
				
				if(parent ==null) {
					current.right = new Node(value);
					break;
				}
				
			}
			
			

		}
	
		
		
		
	}	
	
	public void inOrder() {
		
		Node parent = rootNode;
		Node current;
		
		while(true) {
			current = parent;
		
			if(parent.left!=null) {
				parent = parent.left;
			}
			
		}
		
	}
	
	
	//		10
	//	7		11
	//6	  8
	
public static void main(String[] args) {
	
	BinaryTree bt = new BinaryTree();
	bt.add(10);
	bt.add(7);
	bt.add(6);
	bt.add(8);
	bt.add(11);
	
}

}

