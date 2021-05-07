package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Boj9020 {

	public static void main(String[] args)throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		
		Boolean[] primeArr = new Boolean[9999];
		int arr[] = new int[9999];
		
		for(int j=2; j<=10000; j++) {
				
			for(int k=2; k<=Math.sqrt(j); k++) {
				
				if((j%k)==0) {
					arr[j-2] = j;
					primeArr[j-2] = false;
					break;
				}
				
				
			}
			
			if(primeArr[j-2]==null) {
				arr[j-2] = j;
				primeArr[j-2] = true;
				continue;
			}
		}
		
		
		ArrayList<Integer> sosu = new ArrayList<>();
		
		for(int a=0; a<arr.length; a++) {
			
			if(primeArr[a]) {
				
				sosu.add(arr[a]);
			}
		}
		//System.out.println(sosu);
		int T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i<T; i++) {
			ArrayList<String> answer = new ArrayList<>();
			int N = Integer.parseInt(br.readLine());
			
			int end = 0;
			for(int j=0;j<sosu.size();j++) {
				
				if(sosu.get(j)>N) {
					end=j-1;
					break;
				}
			}
			
			for(int k=0;k<=end;k++) {
			
					int min = 0;
				
					for(int b=0;b<=(sosu.size()-1) ;b++) {
						
						for(int c=b;c<=(sosu.size()-1);c++) {
							
							int sum=0;
							sum += sosu.get(b)+ sosu.get(c);
							min=0;
						
							if(sum==N) {
								
								int remainder = sosu.get(b)-sosu.get(c);
								
								if(min>remainder) {
									min = remainder;
								}

								String str = sosu.get(b).toString();
								String str1 = sosu.get(c).toString();
								
								answer.add(str+" "+str1);
							}else if(sum>N) {
								break;
							}
							
						}
						
					}
	
					
				}
			System.out.println(answer.get(answer.size()-1));
			//answer.removeAll(answer);
			}
			
			
	}

	}
