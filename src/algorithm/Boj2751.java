package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Boj2751 {
	
	public static class BinaryTree {
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
		
		public void inOrderNotRecursive(Node node) {
			
			Stack<Node> st = new Stack();
			Node root = node;
			
			
			if(node.right !=null) {
				node = node.right;
				if(node.right!=null) st.add(node.right);
				st.add(node);
				
				while(node.left!=null) {
					node = node.left;
					if(node.right!=null) st.add(node.right);
					st.add(node);
				
				}
			}
			
			st.add(root);
			
			if(root.left!=null) {
				node = root;
				while(node.left!=null) {
					node = node.left;
					
					if(node.right!=null) st.add(node.right);
					st.add(node);
					
				}
			}
			
			//		    10
			//		7		12
			//	  6  8	  11  13
			//  5 
			
			while(!st.empty()) {
				Node Node = st.pop();
				System.out.println(Node.data);

			}
			
		}
		
	 }
	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		BinaryTree bt = new BinaryTree();
		
		int[] arr = new int[N];
		
		for(int i=0; i<N;i++) {
			int num = Integer.parseInt(br.readLine());
			bt.add(num);
		}
		
		bt.inOrderNotRecursive(bt.rootNode);
	/*	
	int ar[] = {2,4,6,8};
	int ar1[] = {10,5,7,9};
	
	int sort[] = new int[8];
	
	int size = ar.length;
	
	int f = 0;
	int p = 0;
	int i = 0;

	while(f<3 || p<3) {
		
	
			if(ar[f] > ar1[p]) {
				System.out.println("p--"+p);
				sort[i] = ar1[p];
				System.out.println("p:"+sort[i]);
				i++;p++; 
			}
			else{
				System.out.println("f--"+f);
				sort[i] = ar[f];
				System.out.println("f:"+sort[i]);
				i++;f++;
			}
		
	
	}
		
	
	*/
	
	
	
	
	}
	 
}