String text = "apple,banana,cherry";
String result = getValue(text, ',', 1);
// result will be "banana"


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
