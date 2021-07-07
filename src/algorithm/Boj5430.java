package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj5430 {
	
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
			String[] strArr = (str.substring(1, str.length()-1)).split(",");
			
			int rear = 0;
			
			int front = 0;
			
			if(n>1) {
				
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
					
					if(n==0) {
						flag=0;
						break;
					}else if(n==1) {
						
						if(front==1) {
							flag=0;
							break;
						}else {
							front++;
						
						}
					}else {
						if(rear <front) {
							flag = 0;
							break;
						}else {
							if(where==0) {
								front++;
							
							}else {
								rear--;
							}
						}
					}
						
				}
			}
		
			if((count%2)!=0 && flag==1) {
				//거꾸로
				
				sb.append("[");
				for(int k=rear; front<=k; k--) {
					
					if(k!=front) {
						
						sb.append(strArr[k]+",");
					}else {
						
						sb.append(strArr[k]);
					}
					
				}
				sb.append("]"+"\n");
			}else if((count%2)==0 && flag==1){
				
				
				sb.append("[");
				for(int k=front; k<=rear; k++) {
					if(k!=rear) {
					
						sb.append(strArr[k]+",");
					}else {
						
						sb.append(strArr[k]);
					}
				}
				
			
				sb.append("]"+"\n");
			}else {
				sb.append("error"+"\n");
			}
			
			
		
			}
			System.out.println(sb.toString());
		}
	

}
