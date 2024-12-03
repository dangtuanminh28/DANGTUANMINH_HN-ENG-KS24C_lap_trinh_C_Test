#include <stdio.h>
int main(){
	// Khai bao bien va mang 
	int number = 0; 
	int choice, rows, colums, temp;
	int tich = 1;
	int arr[50][50];
	// In ra man hinh 
	do {
	printf("    MENU\n");
	printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
	printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
	printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
	printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
	printf("5. In ra cac phan tu nam tren duong cheo phu\n");
	printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
	printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
	printf("8. Thoat\n");
	printf("Lua chon cua ban: ");
	// Gan gia tri tu nguoi nhap vao
	scanf("%d", &choice);
		// Nhap kich co va gia tri cac phan tu cua mang
		switch(choice) {
		case 1:
            printf("Nhap so hang cua ma tran: ");
            scanf("%d", &rows);
            printf("Nhap so cot cua ma tran: ");
            scanf("%d", &colums);
            printf("Nhap cac phan tu cua ma tran:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < colums; j++) {
                    printf("Phan tu [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &arr[i][j]);
                }
            }
        	printf("\n");
            break;
        // In gia tri cac phan tu cua mang theo ma tran
		case 2:
        printf("     Ma tran:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < colums; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            break;
		// In ra cac phan tu nam tren duong bien va tinh tich
		case 3:
        for (int i = 0; i < colums; i++) {
            printf("%d", arr[0][i]);
            tich *= arr[0][i];
        	}
        for (int i = 1; i < colums; i++) {
            printf("%d", arr[rows - 1][i]);
            tich *= arr[rows - 1][i];
        	}
        for (int i = 1; i < rows - 1; i++) {
            printf("%d", arr[i][0]);
            tich *= arr[i][0];
            }
        for (int i = 1; i < rows; i++) {
            printf("%d", arr[i][colums - 1]);
            tich *= arr[i][colums - 1];
            }
        printf("\n Tich cua cac phan tu tren duong bien la: %d\n", tich);
        break;
        // In ra cac phan tu nam tren duong cheo chinh
        case 4:
            if (rows == colums) {
                for (int i = 0; i < rows; i++) {
                    printf("%d", arr[i][i]);
                }
                printf("\n");
            }
            else
            {
                printf("Phan tu khong hop le\n");
            }
            break;
        // In ra cac phan tu nam tren duong cheo phu
        case 5:
            if (rows == colums)
            {
                for (int i = 0; i < rows; i++)
                {
                    printf("%d", arr[i][rows - i - 1]);
                }
                printf("\n");
            } 
			else
            {
                printf("Phan tu khong hop le\n");
            }
            break;
        // Sap xep duong cheo chinh theo thu tu tang dan
        case 6:
            if (rows == colums) {
                for (int i = 0; i < rows - 1; i++) {
                    for (int j = i + 1; j < rows; j++) {
                        if (arr[i][i] > arr[j][j]) {
                            temp = arr[i][i];
                            arr[i][i] = arr[j][j];
                            arr[j][j] = temp;
                        }
                    }
                }
                printf("Duong cheo chinh sau khi sap xep tang dan: ");
                for (int i = 0; i < rows; i++)
                {
                    printf("%d", arr[i][i]);
                }
                printf("\n");
            }
            else
            {
                printf("Phan tu khong hop le\n");
            }
            break;
    	// Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
        case 7:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &temp);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < colums; j++)
                {
                    if (arr[i][j] == temp)
                    {
                        printf("Gia tri %d xuat hien tai vi tri [%d][%d]\n", temp, i + 1, j + 1);
                    }
                }
            }
            break;
        // Thoat man hinh
        case 8:
            printf("Ket thuc.\n");
            break;
    	default:
        	printf("Lua chon khong hop le, vui long chon lai.\n");
        }
	} while (choice != 8);
	return 0;
}
