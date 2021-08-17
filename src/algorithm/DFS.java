package algorithm;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

class ListGraph{
	
	private ArrayList<ArrayList<Integer>> graph;
	
	public ListGraph(int initSize) {
		
		graph = new ArrayList<>(initSize);
		
		for(int i=0; i<initSize; i++) {
			graph.add(new ArrayList<Integer>());
		}
		
	}
	
	public ArrayList<ArrayList<Integer>> getGraph() {
	
		return graph;
	}
	
	public ArrayList<Integer> getList(int index) {
		
		ArrayList<Integer> list = graph.get(index);
		return list;
	}
	
	public void putComplete(int x, int y) {
		
		getList(x).add(y);
		getList(y).add(x);
	}
	
	public void putSingle(int x, int y) {
		
		getList(x).add(y);
	}
	
	public void printAdjList() {
		int size = graph.size();
		
		for(int i=0; i<size; i++) {
			System.out.print("정점 "+i+"의 인접리스트");
			for(int j=0; j<graph.get(i).size(); j++) {
				System.out.print("-->"+graph.get(i).get(j));
			}
			System.out.println();
		}
	}
	
		
}

public class DFS {

	boolean visited[];
	ListGraph graph;
	int arr[];
	
	
	public DFS(int initSize) {
		visited = new boolean[initSize];
		graph = new ListGraph(initSize);
		arr = new int[initSize];
	}
	
	public void addComplete(int x, int y) {
		
		graph.putComplete(x, y);
	}
	
	public void addSingle(int x, int y) {
		
		graph.putSingle(x, y);
	}
	
	public void printAll() {
		graph.printAdjList();
	}
	
	
	public void search(int index, int arrIndex) {
		visited[index] = true;
		arr[++arrIndex] = index;
		
		ArrayList<Integer> list = graph.getList(index);

		for(int i=0; i<list.size(); i++) {
			
			if(!visited[list.get(i)]) {
				
				search(list.get(i), arrIndex);
			}
				
		}
		System.out.println(index);
		
		if(arrIndex<visited.length-1) {
			System.out.println("arr"+ arrIndex+",,"+(visited.length-1));
			search(arr[arrIndex-1], arrIndex);
		}else {
			return;
		}
		
		
		/*
		for(int i=0;i<arr.length; i++) {
			System.out.println(arr[i]);
		}
		*/
	}
	
	
	
	
	
	public static void main(String[] args)throws IOException {
	
		int initSize = 6;
		DFS dfs = new DFS(initSize);
		      
		dfs.addComplete(0, 1);
		dfs.addComplete(0, 2);
		dfs.addComplete(0, 4);
		dfs.addComplete(1, 2);
		dfs.addComplete(2, 3);
		dfs.addComplete(2, 4);
		dfs.addComplete(3, 4);
		dfs.addComplete(3, 5);
		//dfs.printAll();
		dfs.search(0, -1);
        
		
	}

}		
		
		
		
		
	












/*
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
*/
	/*	
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
	*/	




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