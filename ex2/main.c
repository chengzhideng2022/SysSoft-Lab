#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_READ_LENGTH_FORMAT_SPECIFIER "%100s"


char * convert_to_upper_case ( char * the_string );

int main ( ) {
    // The result of comparing the users regular and upper-case name with strcmp ( )
    int regular_upper_case_comparison_result;
    int year;                                  // The users birth year
    int first_name_length, second_name_length; // The length of the users names
    char first [ MAX_STRING_LENGTH ]="qqq";          // The users first name
    char second [ MAX_STRING_LENGTH ]="qqq";         // The users second name
    char * name="";                               //  The users full name
    char * str="";
                            //  The users second name in upper case
    

    printf ( "Type in your first name: " );
    scanf ( MAX_READ_LENGTH_FORMAT_SPECIFIER, first );
    printf ( "Type in your second name: " );
    scanf ( MAX_READ_LENGTH_FORMAT_SPECIFIER, second );
    
    str = convert_to_upper_case ( second );
    printf ( "Your second name in upper-case is %s \n", str );

    regular_upper_case_comparison_result = strcmp ( second, str );
    if ( regular_upper_case_comparison_result < 0 ) {
        printf ( "According to strcmp(), the upper case version is greater than your second name \n" );
    } else if ( regular_upper_case_comparison_result > 0 ) {
        printf ( "According to strcmp(), the upper case version is less than your second name \n" );
    } else {
        printf ( "According to strcmp(), the upper case version is equal to your second name \n" );
    }

    first_name_length = strlen ( first );
    second_name_length = strlen ( second );
    // We will reseve two extra characters to store a space between the names and the null terminator character
    size_t full_name_length = ( first_name_length + second_name_length + 2 );
    name = malloc ( full_name_length * sizeof ( char ) );
    if (name != NULL)
    {
        strncat(name, first, first_name_length);
        name[first_name_length] = ' ';
    }

    strncat ( & name [ first_name_length + 1 ], second, second_name_length );
    printf ( "Your first and last name concatenated with strncat() yield: \n\t%s \n", name );

    printf ( "Please enter your year of birth: " );
    scanf( "%4d", & year ); 

    size_t year_string_length = 5; // A year string has 4 digits and a null terminator
    size_t full_name_and_year_length = ( full_name_length + year_string_length );
    name = realloc ( name, full_name_and_year_length * sizeof ( char ) );

    /* !!! Important: you can not fetch a string to print from the same address as the destination !!!
         This is a library restriction */
    snprintf ( ( name + full_name_length - 1 ), ( year_string_length + 1 ), " %d", year );

    printf ( "Your full name and birth year concatenated with snprinft() give\n\t%s \n", name );

    sscanf ( name, "%s", first );
    sscanf ( name, "%s", second );
    sscanf ( name, "%d", & year );
    printf ( "Using sscanf on your full name your first name is %s \n", first );
    printf ( "Using sscanf on your full name your second name is %s \n", second );
    printf ( "Using sscanf on your full name your age is %d \n", year );

    return ( 0 );
}


char * convert_to_upper_case ( char * the_string ) {
    size_t string_length = strlen ( the_string );
    char * new_string = malloc ( string_length * sizeof ( char ) );

    for ( size_t current_index = 0; current_index < string_length; ++ current_index ) {
        new_string [ current_index ] = toupper ( the_string [ current_index ] );
    }

    return ( new_string );
}

