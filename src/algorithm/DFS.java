package algorithm;

import java.util.ArrayList;

public class DFS {
	
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
	
	public static boolean[] visited = new boolean[9];
	public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
	
	public static void dfs(int x) {
		
		visited[x] = true;
	}
	
	
	
	public static void main(String[] args) {
		
	
		
		
		
		
		
		
		
		
		
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
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}

}
