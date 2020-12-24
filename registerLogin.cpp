#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// struct Friend {
//   char name[255];
//   int xTeman = 0;
//   int sentRequest = 0;
//   Friend *nextF;
// } *headF, *tailF;

// Friend *createFriend(const char *name){
//   Friend *newFriend = (Friend*)malloc(sizeof(Friend));
//   strcpy(newFriend->name, name);
//   // strcpy(newFriend->password, password);
//   newFriend->nextF=NULL;
//   return newFriend;
// }

struct Node {
  char name[255];
  char password[300];
  int penandaLogin = 0;
  int sentRequest = 0;
  // Friend *Fcurrent;
  Node *next;
} *head, *tail, *Fconnect;

Node *createNode(const char *name, const char *password){
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  strcpy(newNode->password, password);
  newNode->next=NULL;
  return newNode;
}

void title1();
void title2();
void menu();
void menu2();
void Push(const char *name, const char *password);
void regis(const char *name, const char *password);
void P();
// void P2();
void P3();
void P4();
int ceklogin(const char name[]);
int cekUser(const char name[]);

char temp0[255];
int main() {
  menu:
  title1();
  puts("[All User]");
  puts("No.       Username");
  P();
  menu();
  printf(">> ");

  int choose;
  scanf("%d", &choose); getchar();
  puts("----------------------------------------");
  while(choose < 0 || choose > 3) {
    puts("Please input the correct list above.");
    system("pause");
    system("cls");
    goto menu;
  }

  switch(choose) {
    // REGISTER
    case 1: {
      char name[255], pass[255], temp1[255], temp2[255];
      printf("Please type in your username [lowercase || 1..24]: ");
      scanf("%[^\n]", name); getchar(); strcpy(temp1, name);

      printf("Please type in your password [lowercase || 1..24]: ");
      scanf("%[^\n]", pass); getchar(); strcpy(temp2, pass);

      regis(temp1, temp2);
      // puts("Register Successfull!");
      system("pause");
      system("cls");
      goto menu;
      // P();
      break;
    }

    // LOGIN
    case 2: {
      ulangi:
      system("cls");
      title1();
      puts("[All User]");
      puts("No.       Username");
      P();
      menu();
      char name[255], pass[255];
      printf("Username: ");
      scanf("%[^\n]", name); getchar(); strcpy(temp0, name);

      printf("Password: ");
      scanf("%[^\n]", pass); getchar();
      int temp = ceklogin(name);
      if(temp == 1) {
        puts("Login Successfull!");
        system("pause");
        system("cls");
        // goto login;
      }
      else if(temp == 0) {
        puts("Your username or password may be wrong or user not exist.");
        puts("Please try again.");
        system("pause");
        system("cls");
        goto ulangi;
      }
      break;
    }

    // LOGOUT
    case 3: {
      puts("Thank you for using this program!");
      exit(1);
      break;
    }

    case 0: {
      exit(1);
    }
  }

  login:
  title2();
  printf("[All friends of %s]\n", temp0);
  puts("No.       Username");
  // P2();
  menu2();
  printf(">> ");
  int target;
  scanf("%d", &target); getchar();
  puts("----------------------------------------");
  puts("");
  while(target < 1 || target > 6) {
    puts("Please input the correct list above.");
    system("pause");
    system("cls");
    goto login;
  }
  // system("cls");

  switch(target) {
    case 1: {
      goto availableUsers;
      inputUlang:
      title2();
      printf("[All friends of %s]\n", temp0);
      puts("No.       Username");
      // P2();
      menu2();
      puts("");

      availableUsers:
      puts("[All Users]");
      puts("No.       Username");
      // puts("masuk ga sih");
      P3();
      puts("Which user do you want to add?");
      printf(">> ");
      char name[255];
      scanf("%[^\n]", name); getchar();
      int temp = cekUser(name);

      if (temp == 1) {
        puts("");
        printf("-- Your request has been sent to %s --\n", name);
        system("pause");
        system("cls");
      } else {
        puts("");
        printf("-- There's no %s in our database, please input another name --\n", name);
        system("pause");
        system("cls");
        goto inputUlang;
      }
      goto login;
      break;
    }
    case 2: {

      break;
    }
    case 3: {

      break;
    }
    case 4: {
      goto sentFR;
      puts("");
      title2();
      printf("[All friends of %s]\n", temp0);
      puts("No.       Username");
      // P2();
      menu2();
      puts("");

      sentFR:
      printf("[All Friend Requests from %s]\n", temp0);
      puts("No.       Username");
      P4();
      puts("");
      system("pause");
      system("cls");
      goto login;
      break;
    }
    case 5: {

      break;
    }
    case 6: {
      // Kalau user log out, maka akan kembali ke menu awal.
      // Sebelum masuk ke menu awal, buat penandaLogin = 0 untuk user ini
      puts("");
      printf("%s has logged out\n", temp0);
      Node *curr = head;
      int flag=0;
      while(curr){
          if(curr -> penandaLogin == 1){
              curr->penandaLogin = 0;
              // printf("%d\n", curr->penandaLogin);
              // system("pause");
              break;
          }
          curr = curr->next;
      }
      // Tunjukkan berapa lama user sudah memakai program ini
      system("pause");
      system("cls");
      goto menu;
      break;
    }
  }

  return 0;
}

void title1() {
  puts("Oo=====================================oO");
  puts("              STUDY NETWORK              ");
  puts("Oo=====================================oO\n");
}

void title2() {
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  puts("Oo=====================================oO");
  printf("Welcome, %s!\n", temp0);
  puts("Oo=====================================oO");
  printf("Logged in: %s", asctime(timeinfo));
  puts("----------------------------------------\n");
}

void menu() {
  puts("----------------------------------------");
  puts("[1] Register");
  puts("[2] Login");
  puts("[3] Exit");
  puts("----------------------------------------");
  puts("Press 0 and enter to abort an operation");
  puts("----------------------------------------");
}

void menu2() {
  puts("----------------------------------------");
  puts("                >>Menu<<                ");
  puts("----------------------------------------");
  puts("[1] Add Friend");
  puts("[2] Remove Friend");
  puts("[3] View Inbox");
  puts("[4] View Sent Request");
  puts("[5] Add, Edit, Announce, Delete Note");
  puts("[6] Log Out");
  puts("----------------------------------------");
}

void Push(const char *name, const char *password){
  Node *temp = (Node*) createNode(name, password);

  if(!head){
    head = tail = temp;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

void regis(const char *name, const char *password) {
  Node *temp = createNode(name, password);
  Node *curr = head;
  int flag=0;

  while(curr!=NULL){
    if(strcmp(curr->name, name)==0){
      flag=1;
      break;
    }
    curr = curr->next;
  }

  if(flag==1) {
    printf("Username taken.\n");
    system("pause");
    system("cls");
  }
  else {
    Push(name,password);
    puts("Register Successfull!");
  }
}


void P() {
  //30 -> 20 -> 15 -> 40 -> NULL
  //saat sampai di NULL, curr berhenti

  Node *curr = head; //curr adalah index yang akan berjalan

  int count = 1;
  while(curr!=NULL){//kalau di array semacam for
    printf("%-10d %s\n", count, curr->name);
    // printf("%s\n", curr->password);
    curr = curr->next; //curr akan berjalan ke node selanjutnya
    count++;
  }
  // printf("NULL\n");
}

int ceklogin(const char name[]){
    Node *curr = head;
    int flag=0;
    while(curr){
        if(strcmp(curr->name, name)==0){
            flag=1;
            curr->penandaLogin = 1;
            // printf("%d\n", curr->penandaLogin);
            // system("pause");
            break;
        }
        curr = curr->next;
    }
    if(flag==1) {
        return 1; // lanjut ke user interface
    }
    else {
        return 0; //
    }
}

int cekUser(const char name[]) {
    // puts("masuk");
    Node *curr = head;
    int flag=0;
    while(curr) {
        if(strcmp(curr->name, name)==0 && curr->penandaLogin != 1) {
            flag = 1;
            curr->sentRequest = 1;
            printf("%d\n", curr->sentRequest);
            // system("pause");
            break;
        } else if (strcmp(curr->name, name)==0 && curr -> penandaLogin == 1) {
          break;
        }
        curr = curr -> next;
    }
    if(flag==1) {
        return 1; // lanjut ke user interface
    }
    else {
        return 0; //
    }
}

// void P2() {
//   //30 -> 20 -> 15 -> 40 -> NULL
//   //saat sampai di NULL, curr berhenti

//   Node *curr = head; //curr adalah index yang akan berjalan

//   int count = 1;
//   while(curr){//kalau di array semacam for
//     if (curr -> xTeman != 1) {
//       printf("%-10d %s\n", count, curr->name);
//       // printf("%s\n", curr->password);
//       count++;
//     }

//     curr = curr->next; //curr akan berjalan ke node selanjutnya
//   }
//   // printf("NULL\n");
// }

// Menunjukkan user yang bisa dijadikan teman
void P3() {
  //30 -> 20 -> 15 -> 40 -> NULL
  //saat sampai di NULL, curr berhenti

  Node *curr = head; //curr adalah index yang akan berjalan

  int count = 1;
  while(curr){//kalau di array semacam for
    if (curr->sentRequest != 1 && curr -> penandaLogin != 1) {
      printf("%-10d %s\n", count, curr->name);
      // printf("%s\n", curr->password);
      count++;
    }

    curr = curr->next; //curr akan berjalan ke node selanjutnya
  }
  puts("\n");
  // printf("NULL\n");
}

void P4() {
  //30 -> 20 -> 15 -> 40 -> NULL
  //saat sampai di NULL, curr berhenti

  Node *curr = head; //curr adalah index yang akan berjalan

  int count = 1;
  while(curr){//kalau di array semacam for
    if (curr -> sentRequest == 1 && curr -> penandaLogin != 1) {
      printf("%-10d %s\n", count, curr->name);
      // printf("%s\n", curr->password);
      count++;
    }

    curr = curr->next; //curr akan berjalan ke node selanjutnya
  }
  // puts("\n");
  // printf("NULL\n");
}