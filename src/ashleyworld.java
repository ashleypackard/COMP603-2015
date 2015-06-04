import java.util.Scanner;
public class ashleyworld {
public static void main(String[] args) {
Scanner reader = new Scanner(System.in);
char[] arr = new char[30000];
int arrayIndex = 0;
arrayIndex+=1;
arr[arrayIndex]+=9;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
arr[arrayIndex]+=8;
arrayIndex+=1;
arr[arrayIndex]-=1;
}
arrayIndex-=1;
System.out.print(arr[arrayIndex]);
arrayIndex+=1;
arr[arrayIndex]+=7;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
arr[arrayIndex]+=4;
arrayIndex+=1;
arr[arrayIndex]-=1;
}
arrayIndex-=1;
arr[arrayIndex]+=1;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=7;
System.out.print(arr[arrayIndex]);
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=3;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]=0;
arrayIndex+=1;
arr[arrayIndex]+=8;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
arr[arrayIndex]+=4;
arrayIndex+=1;
arr[arrayIndex]-=1;
}
arrayIndex-=1;
System.out.print(arr[arrayIndex]);
arrayIndex+=1;
arr[arrayIndex]+=11;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
arr[arrayIndex]+=8;
arrayIndex+=1;
arr[arrayIndex]-=1;
}
arrayIndex-=1;
arr[arrayIndex]-=1;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]-=8;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]+=3;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]-=6;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]-=8;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]=0;
arrayIndex+=1;
arr[arrayIndex]+=8;
while(arr[arrayIndex]!=0) {
arrayIndex-=1;
arr[arrayIndex]+=4;
arrayIndex+=1;
arr[arrayIndex]-=1;
}
arrayIndex-=1;
arr[arrayIndex]+=1;
System.out.print(arr[arrayIndex]);
arr[arrayIndex]=0;
arr[arrayIndex]+=10;
System.out.print(arr[arrayIndex]);
}
}
