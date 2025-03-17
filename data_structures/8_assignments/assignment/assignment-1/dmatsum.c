#include<stdio.h>

// int sfun(int row, int col,int arr[row][col]){
//     int sum = 0;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
            
//             if(i>j){
//                 sum += arr[i][j];
//             }
//         }
//     }
//     return sum;

// }  

int sfun(int row, int col,int arr[row][col]){
    int sum = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(i>j){
                sum += arr[i][j];
            }
        }
    }
    return sum;

}  



int main(){
    int row,col;
    printf("Enter row\n");
    scanf("%d",&row);
    printf("Enter column\n");
    scanf("%d",&col);
    int arr[row][col];
    // int sum = 0;
    printf("Enter Elements :\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
            // if(i>j){
            //     sum += arr[i][j];
            // }
        }
    }
    int sum;
    sum = sfun(row,col,arr);
    printf("sum is %d",sum);
    return 0;
}