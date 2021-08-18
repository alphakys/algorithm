package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Boj15649 {
/*
	public void permutate(int node) {
	
		visited[node] = true;
		ArrayList<Integer> list = adjList.get(node);
		
		for(int i=0; i<list.size(); i++) {
			if(!visited[list.get(i)]) {
				System.out.println(node +" "+list.get(i));
			}
			
		}
	
		for(int i=0; i<list.size(); i++) {
			if(!visited[list.get(i)]) {
				permutate(list.get(i));
			}
		}
		
		
	}
	*/
	
	
	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String strArr[] = br.readLine().split(" ");
		int N = Integer.parseInt(strArr[0]);
		int M = Integer.parseInt(strArr[1]);
		
		int[] arr = new int[N+1];
		
		for(int i=1; i<=4; i++) {
			arr[i] = i;
		}
		
		int depth = 0;
		
		int i=1;
		
		while(M>depth) {
			System.out.println(arr[i++]);
			depth++;
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}	
	
}