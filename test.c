/* The test file! */

#include<stdio.h>
#include "queuemanager.c"

void printprocess(struct process_control_block process);
void listQ();

void printprocess(struct process_control_block process) {
  int i = 0;

  printf("pid: %d\n", process.pid);
  printf("psw: %d\n", process.psw);
  printf("page_table: %d\n", process.page_table);
  printf("regs:\n");
  for (i = 0; i < NUM_REGS; i++) {
    printf("  %d\n", process.regs[i]);
  }
}

void listQ() {
  struct process_control_block *temp = head;
  while (temp) {
    printprocess(*temp);
    temp = temp->next;
  }
}

int main() {
  listQ();
  return(0);
}