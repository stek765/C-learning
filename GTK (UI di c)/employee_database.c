#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Struct to store employee data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Employee;

// Function to add employee to the database
void add_employee(Employee *employee, GtkWidget *name_entry, GtkWidget *email_entry, GtkWidget *listbox) {
    strcpy(employee->name, gtk_entry_get_text(GTK_ENTRY(name_entry)));
    strcpy(employee->email, gtk_entry_get_text(GTK_ENTRY(email_entry)));

    // Append employee details to the list box
    char entry_text[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 10];  // 10 for formatting
    sprintf(entry_text, "Name: %s, Email: %s", employee->name, employee->email);
    gtk_list_box_insert(GTK_LIST_BOX(listbox), gtk_label_new(entry_text), -1);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *name_label, *email_label;
    GtkWidget *name_entry, *email_entry;
    GtkWidget *add_button;
    GtkWidget *listbox;
    Employee employee;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Employee Database Utility");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create grid layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create labels
    name_label = gtk_label_new("Name:");
    email_label = gtk_label_new("Email:");

    // Create entry fields
    name_entry = gtk_entry_new();
    email_entry = gtk_entry_new();

    // Create add button
    add_button = gtk_button_new_with_label("Add Employee");

    // Connect button click signal to callback function
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_employee), &employee);

    // Create list box
    listbox = gtk_list_box_new();

    // Add widgets to grid layout
    gtk_grid_attach(GTK_GRID(grid), name_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), email_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), email_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), listbox, 0, 3, 2, 1);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
