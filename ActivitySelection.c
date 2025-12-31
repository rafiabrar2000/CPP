#include <stdio.h>

struct Activity {
  char id[6];
  int start;
  int finish;
};



int main(void) {

  //activities
  struct Activity activities[6] = {
    {"2", 1, 2},
    {"3", 3, 5},
    {"1", 0, 6},
    {"5", 6, 9},
    {"4", 7, 11},
    {"6", 8, 12},
  };

  //number of activities
  int n = 8;

  activitySelection(activities, n);

  return 0;
}

void activitySelection(Activity activities[], int n) {
  //variables
  int i, j;

  Activity temp;

  //step 1
  //sort the activities as per finishing time in ascending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - 1; j++){
      if(activities[j].finish > activities[j+1].finish) {
        temp = activities[j];
        activities[j] = activities[j+1];
        activities[j+1] = temp;
      }
    }
  }

  //sorted
  printf("Sorted activities as per finish time (ascending order)\n");
  printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", activities[i].id, activities[i].start, activities[i].finish);
  }

  //step 2
  //select the first activity
  printf("-----Selected Activities-----\n");
  printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  printf("%10s %10i %10i\n", activities[0].id, activities[0].start, activities[0].finish);

  //step 3
  //select next activity whose start time is greater than
  //or equal to the finish time of the previously selected activity
  i = 0;
  for(j = 1; j < n; j++) {
    if(activities[j].start >= activities[i].finish) {
      printf("%10s %10i %10i\n", activities[j].id, activities[j].start, activities[j].finish);
      i = j;
    }
  }
}
