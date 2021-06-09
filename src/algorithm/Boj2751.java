package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Boj2751 {
	
	static class BST{
		
		class Node{
			
			int data;
			Node left;
			Node right;
			
			public Node(int value) {
				this.data = value;
				this.left=null;
				this.right=null;
			}
		}	
		Node rootNode;	
			
		public void add(int value) {
			
			if(rootNode==null) {
				rootNode = new Node(value);
				return;
			}else {
				
				Node parent = rootNode;
				Node current;
				
				while(true) {
					current = parent;
				
					if(parent.data>value) {
						parent = parent.left;
						
						if(parent==null) {
							current.left = new Node(value);
							break;
						}
					}else {
						parent = parent.right;
						
						if(parent==null) {
							current.right = new Node(value);
							break;
						}
					}
					
				}	
			}	
		}
		//add function		
		
		//			13
		//	  10  		14
		//	 7	11
		//	4 8 
		
		public void show(Node node) {
			
			Stack<Node> st = new Stack<>();
			
			while(true) {
				
				if(node!=null) {
					st.push(node);
					node = node.left;
					if(node==null) {
						System.out.println(st.pop().data);
					}
					
				}
		
			}
			
			
			
		}

		public void inOrder(Node node) {
			
			if(node !=null) {
				if(node.left!=null) inOrder(node.left);
				System.out.println(node.data);
				if(node.right!=null) inOrder(node.right);
			}else {
				System.out.println("rootNode가 존재하지 않습니다.");
			}
		}//inOrder function
			
	}//BST class
	
	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BST bst = new BST();
		
		int N = Integer.parseInt(br.readLine());
	
		for(int i=0; i<N; i++) {
			int num = Integer.parseInt(br.readLine());
			bst.add(num);
			
		}
		
		bst.show(bst.rootNode);
		
	}

}