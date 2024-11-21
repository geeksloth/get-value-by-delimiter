# get-value-by-separator

Extracts a substring from a given string based on a separator and an index.
Works on native C language and Arduino.

# Usage
```cpp
String text = "apple,banana,cherry";

String result = getValue(text, ',', 1);
// result will be "banana"
```

In this example, the function will return "banana" as it is the substring at index 1 when the string is split by the comma separator.

# Code
This function searches for the nth occurrence of a separator character in the input string and returns the substring located at that position.
```cpp
/**
 * @brief Extracts a substring from a given string based on a separator and an index.
 *
 * This function searches for the nth occurrence of a separator character in the input string
 * and returns the substring located at that position.
 *
 * @param text The input string from which the substring will be extracted.
 * @param separator The character used to separate the substrings within the input string.
 * @param index The zero-based index of the substring to be extracted.
 * @return A substring located at the specified index, or an empty string if the index is out of bounds.
 */
String getValue(String text, char separator, int index) {
  int found = 0;
  int string_index[] = {0, -1};
  int max_index = text.length()-1;
  for (int i = 0; i <= max_index && found <= index; i++) {
    if (text.charAt(i) == separator || i == max_index){
      found++;
      string_index[0] = string_index[1] + 1;
      string_index[1] = (i == max_index) ? i + 1 : i;
    }
  }
  return found > index ? text.substring(string_index[0], string_index[1]) : "";
}
```


