package algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class ff {
	
	public static ArrayList<Integer> Revert(ArrayList<Integer> ar) {
		
		int last = ar.size();
		ArrayList<Integer> a = new ArrayList<>();
		
		for(int i=last-1; i>=0; i--) {
			a.add(ar.get(i));
		}
		
		return a;
	}
	
	public static void Delete(ArrayList<Integer> ar, int where, int flag) {
		int size = ar.size();
		
		if(size==0) {
			flag=0;
		
		}else {
			if(where==0) {
				ar.remove(0);
			}else {
				ar.remove(ar.size()-1);
			}
		}
		
		
	}

	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T;i++) {
			//함수 영역
			String[] fnc = br.readLine().split("");
			
			//배열 개수 영역
			int n = Integer.parseInt(br.readLine());
			
			//배열 String --> 숫자 영역
			String str = br.readLine();
			
			String[] strArr = str.substring(1, str.length()-1).split(",");
			
			int length = strArr.length;
			
			ArrayList<Integer> ar = new ArrayList<>();
			
			for(int j=0; j<length;j++) {
				
				if("".equals(strArr[j])) {
					return;
				}else {
					ar.add(Integer.parseInt(strArr[j]));
				}
				
			}
		
			//함수 R,D 수행 영역
			int size = fnc.length;
			int where =0;
			int count=0;
			int flag =1;
			
			for(int k=0;k<size;k++) {

				if("R".equals(fnc[k])) {
					if(where==0) {
						where =1;
					}else {
						where =0;
					}
					count++;
				}else {
					ff.Delete(ar, where, flag);
				
				}
			}
			System.out.println(flag);
			if((count%2)!=0 && flag==1) {
			
				System.out.println(ff.Revert(ar));
			}else if((count%2)==0 && flag==1){
				
				System.out.println(ar);
			}else {
				System.out.println("error");
			}
			
		
			}
			
		}
	

}
