import java.util.*;
class  lcs{
    static String x,y;
    static Scanner sc;
    static int m,n;
    static int b[][],c[][];
    public static void main(String[] args) {
        sc=new Scanner(System.in);
        System.out.println("Enter x");
        x=sc.nextLine();
        System.out.println("Enter y");
        y=sc.nextLine();
        m=x.length();
        n=y.length();   
        System.out.println(m+","+n);
        b=new int[m+1][n+1];
        c=new int[m+1][n+1];
        for(int i=0;i<=m;i++){
            c[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            c[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x.charAt(i-1)==y.charAt(j-1)){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]=1;  //1=/
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]=0;  //0=^
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]=-1; //-1=<-
                }
            }
        }
        System.out.println("The arrow table:1=diagonal,0=up,-1=left");
        display(b);
        System.out.println("c:");
        display(c); 
        System.out.println("lcs:");
        printLcs(b, x, m, n);
    }
    static void display(int arr[][]){
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("-------------");
    }
    static void printLcs(int b[][],String x,int i,int j){
        if(i==0 || j==0)
            return;
        if(b[i][j]==1){
            printLcs(b,x,i-1,j-1);
            System.out.print(x.charAt(i-1));            
        }
        else if(b[i][j]==0){
            printLcs(b, x, i-1, j);
        }
        else
            printLcs(b, x, i, j-1);
    }
}