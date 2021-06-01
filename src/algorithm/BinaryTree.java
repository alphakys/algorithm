package algorithm;

import java.util.TreeSet;

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
