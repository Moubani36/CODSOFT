#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int checkAnswer(Question q, int user_answer) {
    return (user_answer == q.correct_option);
}

int user_answer = -1;

void* getUserInput(void* arg) {
    scanf("%d", &user_answer);
    return NULL;
}

int main() {
    srand(time(NULL));

    Question original_questions[MAX_QUESTIONS] = {
        { "Which bird lays the largest egg?", { "Owl", "Ostrich", "Kingfisher", "Woodpecker" }, 2 },
        { "How many legs does a spider have?", { "7", "8", "6", "5" }, 2 },
        { "Where does the President of the United States live while in office?", { "The White House", "The Parliament", "House of Commons", "Washington DC" }, 1 },
        { "Which state is famous for Hollywood?", { "Sydney", "California", "New York", "Paris" }, 2 },
        { "What is a group of lions called?", { "Drift", "Pride", "Flock", "Drove" }, 2 }
    };

    Question questions[MAX_QUESTIONS];
    memcpy(questions, original_questions, sizeof(original_questions));

    int num_questions = MAX_QUESTIONS;
    int score = 0;

    printf("Hola! Here's your Quiz Game!\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_index = rand() % num_questions;
        Question current_question = questions[random_index];
        displayQuestion(current_question);

        pthread_t thread;
        user_answer = -1;
        pthread_create(&thread, NULL, getUserInput, NULL);

        for (int j = 0; j < 10; j++) {
            sleep(1);
            if (user_answer != -1) break;
        }

        pthread_cancel(thread);

        if (user_answer >= 1 && user_answer <= 4) {
            if (checkAnswer(current_question, user_answer)) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %d. %s\n", current_question.correct_option, current_question.options[current_question.correct_option - 1]);
            }
        } else {
            printf("Time's up! The correct answer is %d. %s\n", current_question.correct_option, current_question.options[current_question.correct_option - 1]);
        }

        questions[random_index] = questions[num_questions - 1];
        num_questions--;
    }

    printf("Well Done Champ !!!! Quiz completed! Your score: %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}

