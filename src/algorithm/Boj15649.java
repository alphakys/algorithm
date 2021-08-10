package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

  class Node {
	
		Node nextNode;
		int value;
		
		Node(int v){
			this.value = v;
		}
		
	}

  class BackTracking{
		
		Node rootNode;
		
		void permutation(int start, int end, int count) {
			
			
			if(rootNode==null) {
				
				rootNode = new Node(start);
				permutation(start+1, end, count);
			}else {
				
				Node parentNode = rootNode;
				Node currNode = parentNode.nextNode; 
				if(parentNode.value!=start &&start<=end) {
					
					currNode = new Node(start);
					
				}
				
				
				
			}
		}
		
		
	}


public class Boj15649 {
	
	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String strArr[] = br.readLine().split(" ");
		int N = Integer.parseInt(strArr[0]);
		int M = Integer.parseInt(strArr[1]);
		
		BackTracking bt = new BackTracking();
		bt.rootNode = new Node(1);
		bt.permutation(1, 4, M);
	
	
	
	
	
	
	}	
	
}