#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

typedef enum day  day;

day find_next_day(day d);

int main(int argc, char *argv[]) {
    day current_day = mon; // Assume today is Monday
    day next_day = find_next_day(current_day);
    
    printf("Today is %d\n", current_day); // Output: Today is 1 (assuming Monday is represented by 1)
    printf("Next day is %d\n", next_day); // Output: Next day is 2 (assuming Tuesday is represented by 2)
    
    return 0;
}

day find_next_day(day d){
    day next_day;
    
    switch (d) {
        case sun:
            next_day = mon;
            break;
        case mon:
            next_day = tue;
            break;
        case tue:
            next_day = wed;
            break;
        case wed:
            next_day = thu;
            break;
        case thu:
            next_day = fri;
            break;
        case fri:
            next_day = sat;
            break;
        case sat:
            next_day = sun;
            break;
    }
    return next_day;
}
