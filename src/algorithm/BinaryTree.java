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
		}else {
			
			Node head;
			Node current;
			
			while(true) {
				
				if(rootNode.data> data) {
				
					if(rootNode.left==null) {
						rootNode.left = new Node(data);
					}else {
						if(rootNode.left>data) {
							
						}
					}
				
				
				
				
				}

			}
	
		}
		
		
	}	
	
}
