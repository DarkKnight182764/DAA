import java.util.*;
class al{
    static int n,e1,e2,x1,x2,f1[],f2[],l1[],l2[],res[],num_test;
    static int a[][],t[][];
    static Scanner sc;
    public static void main(String[] args) {
        sc=new Scanner(System.in);
        //System.out.println("Enter number of toll booths");
        num_test=sc.nextInt();
        res=new int[num_test];
        for(int x=0;x<num_test;x++){
            n=sc.nextInt();
            a=new int[2][n+1];
            t=new int[2][n+1];
            //System.out.println("Enter initial cost to go from starting to 1st toll on 1st track(=e1) and e2");
            e1=/*sc.nextInt();*/0;
            e2=0;/*sc.nextInt();*/
            //System.out.println("Enter final cost to go from last toll on 1st track to end(=x1) and x2");
            x1=0;
            x2=0;
            //System.out.println("Enter tolls along the tracks");
            for(int i=0;i<2;i++){
                for(int j=1;j<=n;j++){
                    a[i][j]=sc.nextInt();
                }
                //System.out.println("Enter along the next track");
            }
            //System.out.println("Enter tolls to cross over from tracks");        
            for(int i=0;i<2;i++){
                for(int j=1;j<n;j++){
                    t[i][j]=sc.nextInt();
                }
            // System.out.println("Enter along the next track");
            }
            f1=new int[n+1];
            f2=new int[n+1];
            res[x]=fw();
        }  
        for(int i=0;i<num_test;i++){
            System.out.println(res[i]);
        }      
        //display();
    }   
    static int fw(){
        f1[1]=e1+a[0][1];
        f2[1]=e2+a[1][1]; 
       // l1=new int[n+1];
        //l2=new int[n+1];
        for(int j=2;j<=n;j++){
            if(f1[j-1]+a[0][j]<=f2[j-1]+t[1][j-1]+a[0][j]){
                f1[j]=f1[j-1]+a[0][j];
                //l1[j]=1;
            }           
            else{
                f1[j]=f2[j-1]+t[1][j-1]+a[0][j];
                //l1[j]=2;
            }           
            if(f2[j-1]+a[1][j]<=f1[j-1]+t[0][j-1]+a[1][j]) {
                f2[j]=f2[j-1]+a[1][j];
                //l2[j]=2;                
            }
            else{
                f2[j]=f1[j-1]+t[0][j-1]+a[1][j];
                //l2[j]=1;
            }
        } 
        return (Math.min(f1[n], f2[n]));
    } 
    static void display(){
        System.out.println("f1");
        for(int i=1;i<=n;i++)
            System.out.print(f1[i]+ " ");
        System.out.println("f2");
        for(int i=1;i<=n;i++)
            System.out.print(f2[i]+" ");        
    }
}