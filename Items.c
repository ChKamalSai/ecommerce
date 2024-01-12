#include<stdio.h>
#include<stdlib.h>
struct Item{
    char name[50];
    int quantity;
    int price;
};
    struct Item items[100];
    int count=0;

void addItem( struct Item newItem ){
    items[count]=newItem;
    // printf("%s %d %d\n",items[count].name,items[count].price,items[count].quantity);
    count++;
    // printf("%d\n",count);
}
void removeItem( int itemNo ){
    for(int i=itemNo - 1;i<count-1;i++){
        items[i]=items[i + 1];
    }
    count--;
}
void updatePrice( int itemNo, int newPrice){
    items[itemNo - 1].price=newPrice;

}
int readFromFile(){
    FILE *ItemsFile;
    ItemsFile = fopen( "Items.txt", "r" );
    char line[100];
    if ( ItemsFile==NULL )
    return 0;    
    while ( fgets( line, sizeof( line ), ItemsFile ) ){
        sscanf( line, "%s %d %d", items[count].name, &items[count].quantity, &items[count].price );
        count++;
    }
    fclose( ItemsFile );
    return 1;
}
int writeToFile(){
    FILE *ItemsFile;
    ItemsFile = fopen( "Items.txt", "w" );
    if ( ItemsFile==NULL )
    return 0;
    for( int i=0;i<count;i++ ){
        fprintf( ItemsFile, "%s %d %d\n", items[i].name, items[i].quantity, items[i].price );
    }
    fclose( ItemsFile );
    return 1;
}
void display(){
    for( int i=0;i<count;i++){
        printf( "%s %d %d\n", items[i].name, items[i].quantity, items[i].price);
    }
}
int main(){ 
    int a = readFromFile();
    if (a == 0) {
        printf("Unable to read from file\n");
    } else {
        printf("Read from file successful\n");
    }

    // Adding an item
    struct Item newItem1={"Banana",12,60};
    struct Item newItem2={"Apple",5,120};
    struct Item newItem3={"Mango",4,100};
    // printf("%s %d %d\n",newItem1.name,newItem1.price,newItem1.quantity);
    // addItem(newItem1);
    // addItem(newItem2);
    // addItem(newItem3);

    display();
    // Removing an item
    // removeItem(1);
    // printf("/////\n");
    // display();
    // // Updating price of an item
    // updatePrice(2, 10);
    // printf("/////\n");
    // display();
    

    int b = writeToFile();
    if (b == 0) {
        printf("Unable to write to file\n");
    } else {
        printf("Write to file successful\n");
    }

    return 0;
}
