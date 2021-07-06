package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ff {
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T;i++) {
			//함수 영역
			String[] fnc = br.readLine().split("");
			
			//배열 개수 영역
			int n = Integer.parseInt(br.readLine());
			
			//배열 String --> 숫자 영역
			String str = br.readLine();
			
			int length=0;
			String[] strArr = null;
			
			int rear = 0;
			
			int front = 0;
			
			if(n>1) {
				strArr = (str.substring(1, str.length()-1)).split(",");
				length= strArr.length;
				rear = length-1;
			}
			
			
			//함수 R,D 수행 영역
		
			int where =0;
			
			
			
			int count=0;
			int flag =1;
			
			int size = fnc.length;
			for(int k=0;k<size;k++) {
				
				if("R".equals(fnc[k])) {
					if(where==0) {
						where =1;
					}else {
						where =0;
					}
					count++;
				}else {
					
					if(rear ==front) {
						flag = 0;
					}else {
						if(where==0) {
							front++;
						
						}else {
							rear--;
						}
					}
					
				}
			}
			
			if((count%2)!=0 && flag==1) {
				//거꾸로
				System.out.print("[");
				for(int k=rear; front<=k; k--) {
					
					if(k!=front) {
						System.out.print(strArr[k]+",");
					}else {
						System.out.print(strArr[k]);
					}
					
				}
				System.out.println("]");
			}else if((count%2)==0 && flag==1){
				
				System.out.print("[");
				
				for(int k=front; k<=rear; k++) {
					if(k!=rear) {
						System.out.print(strArr[k]+",");
					}else {
						System.out.print(strArr[k]);
					}
				}
				
				System.out.println("]");
			}else {
				System.out.println("error");
			}
			
		
			}
			
		}
	

}
