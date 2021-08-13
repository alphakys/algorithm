package algorithm;

import java.io.IOException;
import java.util.LinkedList;

class DfsGraph{
	
	private int[][] graph;
	
	public DfsGraph(int size){
		
		this.graph = new int[size+1][size+1];
	}
	

	public int[][] getGraph() {
		
		return this.graph;
	}
	
	public boolean isEmpty() {
		return graph ==null;
	}
	
	public void addSingle(int x, int y) {
		graph[x][y] = 1;
	}
	
	public void addComplete(int x, int y) {
		graph[x][y] = graph[y][x] = 1;
	}
	
	public void deleteSingle(int x, int y) {
		graph[x][y] = 0;
	}
	
	public void deleteComplete(int x, int y) {
		graph[x][y] = graph[y][x] = 0;
	}
	
	public void print() {
		for(int i=1; i<graph.length; i++) {
			
			for(int j=1; j<graph[i].length; j++) {
				System.out.print(graph[i][j] + " ");
			}
			System.out.println();
		}
		
	}
	
}












public class DFS {

	public static void main(String[] args)throws IOException {
		
	DfsGraph gr = new DfsGraph(6);
	
	gr.addComplete(1, 2);
	gr.addComplete(1, 3);
	gr.addComplete(2, 4);
	gr.addComplete(2, 3);
	gr.addComplete(3, 4);
	gr.addComplete(3, 5);
	gr.addComplete(4, 5);
	gr.addComplete(4, 6);
	
	gr.print();
		
	}

}



/*
public static int factorial(int i) {
	
	
	if(i==1)
		return 1;
	else
		return i*factorial(i-1);
	
}

public static int gcd(int a, int b) {
	
	if(a%b==0) {
		return b;
	}else {
		
		return gcd(b, a%b);
	}

}
*/

/*
Stack<Integer> st = new Stack();
st.add(1);
st.add(2);
st.add(3);
st.add(4);

while(!st.empty()) {
	System.out.println(st.pop());
}
System.out.println("=================");
Queue<Integer> q = new LinkedList<>();
q.offer(5);
q.offer(4);
q.offer(3);
q.poll();
q.offer(11);

while(!q.isEmpty()) {
	System.out.println(q.poll());
}
*/

//DFS d = new DFS();

//System.out.println(factorial(5));
//System.out.println(gcd(22, 5));