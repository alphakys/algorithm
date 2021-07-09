package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj1157 {
	
	public Node root = null;
	
	class Node{
		String value;
		int count;
		Node left;
		
		Node(String element){
			this.value = element;
			this.count = 1;
		}
	}
	
	private void add(String element) {
		
		if(root==null) {
			root = new Node(element);
			return;
		}else {
			Node current = root;
			while(true) {
				
				if(current.value.equals(element)) {
					current.count++;
					break;
				}else if(current.left ==null){
					current.left = new Node(element);
					break;
				}else {
					current = current.left;
				}
			}		
		}
	}
	

	private Node search(Node root) {
		
		if(root==null) {
			
			return null;
		}else {
			Node current = root;
			Node maxNode = root;
			Node equal = null;
			
			while(true) {
				if(current.left!=null) {
					current = current.left;
					if(maxNode.count <current.count) {
						maxNode = current;
						
					}else if(maxNode.count==current.count) {
						equal = current;
					}
					
				}else {
					if(equal!=null) {
						if(equal.count==maxNode.count) {
							maxNode.value = "?";
						}
					}
					
					return maxNode;
				}
			}
		}
		
	}
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] strArr = br.readLine().toUpperCase().split("");
				
		int len = strArr.length;
	
		Boj1157 bo = new Boj1157();
		
		for(int i=0; i<len; i++) {
			bo.add(strArr[i]);
		
		}
		bw.write((bo.search(bo.root).value));
		bw.flush();
		
		
	}

}
