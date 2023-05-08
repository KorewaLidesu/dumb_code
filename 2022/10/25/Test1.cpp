#include <iostream>

int sizeOf(char string[]) {
	int i = 0;
	while(string[i] != '\0') i++;
	return i;
}

int sizeOf$upper(char string[]) {
	int i = 0;
	int count = 0;
	while (string[i] != '\0') {
		if ((string[i] >= 'A') && (string[i] <= 'Z')) count++;
		i++;
	}
	return count;
}

int sizeOf$word(char string[]) {
	int i = 0;
	int count = 0;
	while (string[i] != '\0') {
		//Word is counted if the next bit contain space
		if ((string[i] != ' ') && (string[i+1] == ' ')) count++;
		i++;
		//This will only count words that have space next to it
	}
	//Check the last before NUL
	if((string[i-1] != ' ') && (string[i-1] != '\0')) count++;
	return count;
}

char* toLower(char *string) {
	int t = sizeOf(string);
	if (t > 0) {
		int i = 0;
		char output[t];
		while (string[i] != '\0') {
			output[i] = string[i];
			if ((output[i] >= 'A') && (output[i] <= 'Z')) output[i] += 32;
			std::cout<<output[i];
			i++;
		}
		return output;
	}
}

char* toReverse(char string[]) {
	int t = sizeOf(string);
	if (t > 0) {
		if (t < 2) {return string;}
		char output[t];
		for(int i = 0; i < t ; i++) {
			output[i] = string[t - 1 - i];
		}
		printf("");
		return output;
	}
}

int main() {
	int max = 100;
	if (max >= 1) {
		char s[max] = "";
		std::cout<<"Nhap xau ki tu: ";
		std::cin.getline(s, max);
		printf("Dem so ky tu cua chuoi: %d\n", sizeOf(s));
		printf("Dem so ky tu in hoa cua chuoi: %d\n", sizeOf$upper(s));
		printf("Dem so tu cua chuoi: %d\n", sizeOf$word(s));
		printf("Chuyen doi in hoa thanh in thuong: %s\n", toLower(s));
		printf("Dao nguoc chuoi: %s\n", toReverse(s));
	}
}
