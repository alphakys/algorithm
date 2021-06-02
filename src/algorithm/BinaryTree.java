package algorithm;

class Node{
		
	int data;
	Node left;
	Node right;
	
	public Node(int value) {
		this.data = value;
		this.left = null;
		this.right = null;
	}
		
}

public class BinaryTree{

	Node rootNode;
	
	public void add(int value) {
		
		
		if(rootNode==null) {
				rootNode = new Node(value);
				System.out.println("root:"+value);
				return;
		}else {
			
			Node parent = rootNode;
			Node current;
			
			while(true) {
				
				current = parent;//루트
				if(parent.data>value) {
					
					parent = parent.left;//레프트
					
					if(parent==null) {
						current.left = new Node(value);
						return;
					}
				}else {
					
					current = parent;//루트
					if(parent.data>value) {
						
						parent = parent.left;//레프트
						
						if(parent==null) {
							current.left = new Node(value);
							return;
						}
					}
			
				}
			
			}
			
		}
		
	}
	
	public void remove(int value) {
		
		if(rootNode==null) {
			System.out.println("노드가 존재하지 않습니다.");
		}else {
			
			Node parent = rootNode;
			Node current;
			
			while(true) {
				
			}
		}
		
		
		
		
	}
	
	
	
	
public static void main(String[] args) {
	
	BinaryTree bt = new BinaryTree();
	bt.add(10);
	bt.add(7);
	bt.add(6);
	
}
	
	
	
}










/*
public class BinaryTree {
	//필드
	Node rootNode = null;

	public class Node{
		
		int data;
		Node left;
		Node right;
		
		public Node(int data) {
			this.data = data;
			left = null;
			right = null;
		}
		
	}
	

	public void add(int data) {
		
		if(rootNode ==null) {
			rootNode = new Node(data);
			
		}
			
		Node parent = rootNode;
		Node current;
			
		while(true) {
			
			current = parent;
			
			if(parent.data> data) {
				
				parent = parent.left;
				
				if(parent ==null) {
					current.left = new Node(data);
					break;
				}
		
			}else {
				
				parent = parent.right;
				
				if(parent ==null) {
					current.right = new Node(data);
					break;
				}
				
			}
			
			

		}
	
		
		
		
	}	
	
}
*/