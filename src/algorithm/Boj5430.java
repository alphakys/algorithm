package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Boj5430 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T;i++) {
			String[] fnc = br.readLine().split("");
			
			int n = Integer.parseInt(br.readLine());
			String str = br.readLine();
			if(n==0) {
				System.out.println("error");
				continue;
			}else {
				
				String[] strArr = str.substring(1, str.length()-1).split(",");
			
				int length = strArr.length;
				
				int[] a = new int[length];
			
				for(int j=0; j<length;j++) {
					a[j] = Integer.parseInt(strArr[j]);
					
				}
				
				int size = fnc.length;
				for(int k=0;k<size;k++) {
					//null 값 안나오게 처리
					if("R".equals(fnc[k])) {
						Boj5430.Revert(a);
					}else {
						
						int[] b = null;
						
						if(a.length==0) {
							System.out.println("error");
							break;
						}else {
							int leng = a.length;
							
							b = new int[leng-1];
							
							for(int j=0;j<leng-1 ;j++) {
								b[j] = a[j+1];
							}
							a = new int[leng-1];
							
							for(int z=0;z<leng-1 ;z++) {
								a[z] = b[z];
								
							}
						}
					}
				}
				
				if(a.length!=0) {
					System.out.print("[");
					for(int x=0;x<a.length ;x++) {
						
						if(x!=a.length-1) {
							System.out.print(a[x]+",");
						}else {
							System.out.print(a[x]);
						}
						
					}
					System.out.print("]");
					System.out.println();
				}
				
				
				
			}
			
		}
	
	}
	
	public static int[] Revert(int[] a) {
		Stack<Integer> st = new Stack<>();
		
		int length = a.length;
		
		for(int i=0;i<length ;i++) {
			st.push(a[i]);	
		}
		
		for(int i=0;i<length ;i++) {
			a[i] = st.pop();
		}
		
		return a;
	}
	
}
