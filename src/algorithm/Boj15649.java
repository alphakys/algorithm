package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

  class BackTracking{
		
	class Node {
	
		Node childNode[];
		int value;
		int level;
		
		Node(int v, int level){
			this.value = v;
			this.level = level;
			this.childNode = new Node[2];
		}
	
	}
		
	Node rootNode = null;
	
	public void permutation(Node n, int level) {

		if(rootNode==null) {
			 
			rootNode = new Node(100, level);
			permutation(rootNode, level+1);
			
		}else {
			
			Node currentNode = n;
			
			while(true) {
				//System.out.println(n.level+","+n.value);
				if(currentNode.childNode==null && level<4) {
					
					Node trueNode = new Node(1,level);
					Node falseNode = new Node(0,level);
					System.out.println(trueNode.value+","+trueNode.level);
					System.out.println(falseNode.value+","+falseNode.level);
					currentNode.childNode[0] = trueNode;
					currentNode.childNode[1] = falseNode;
					
					permutation(trueNode, level+1);
					permutation(falseNode, level+1);
				}else {
					break;
				}
				
			}
		}
		
		
		
		
	}
	
	public void levelTraverse(Node node) {
		Queue<Node> q = new LinkedList<>();

		while(true) {
			Node currentNode = node;
			
			if(currentNode.childNode[0]==null) {
				System.out.println("sdfas");
				q.add(currentNode.childNode[0]);
				q.add(currentNode.childNode[1]);
				levelTraverse(currentNode.childNode[0]);
				levelTraverse(currentNode.childNode[1]);
			}else {
				break;
			}
			
			
		}
		
		while(!q.isEmpty()) {
			System.out.println(q.poll());
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
	
		bt.permutation(bt.rootNode, 0);
		//bt.levelTraverse(bt.rootNode);
	
	
	
	}	
	
}