package algorithm;


public class BinaryTree {
	//필드
	public Node rootNode = null;

	public class Node{
		
		int data;
		Node left;
		Node right;
		
		public Node(int value) {
			this.data = value;
			this.left = null;
			this.right = null;
		}
		
	}
	

	public void add(int value) {
		
		if(rootNode ==null) {
			rootNode = new Node(value);
			return;
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
	
	public void inOrder(Node node) {
	
		if(node!=null) {
			System.out.println(node.data);
			if(node.left!=null) System.out.println("l");inOrder(node.left);
			System.out.println(node.data);
			if(node.right !=null) System.out.println("r");inOrder(node.right);
			
		}
	
	}
	
	
	//			10
	//		7		11
	//	 6	  8			13
	// 5   
	public static void main(String[] args) {
		
		BinaryTree bt = new BinaryTree();
		bt.add(10);
		bt.add(7);
		bt.add(6);
		bt.add(5);
		bt.add(8);
		bt.add(11);
		bt.add(13);
		bt.inOrder(bt.rootNode);
	}

}

