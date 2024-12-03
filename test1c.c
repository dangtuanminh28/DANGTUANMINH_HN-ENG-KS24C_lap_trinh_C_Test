#include <stdio.h>
int main(){
	// Khai bao bien va mang
    int arr[100];
    int number = 0;
    int choice;
    int check = 0;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to cua mang\n");
        printf("5. Them phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index cua no\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice){
        // Nhap so phan tu can nhap va gia tri cac phan tu
        case 1:
            check = 1;
            printf("nhap so phan tu co trong man(1-100): ");
            scanf("%d", &number);
            if(number < 0 || number > 100){
                printf("so phan tu mang khong hop le");
                break;
            }
            for(int i = 0; i < number; i++){
                printf("arr[%d]= ", i);
                scanf("%d", &arr[i]);
            }
            break;
        // In ra gia tri cac phan tu dang quan ly
        case 2: 
            if(check == 0){
                printf("Xin hay nhap mang");
                break;
            }
            for(int i = 0; i < number; i++){
                printf("arr[%d]= %d\n", i, arr[i]);
            }
            break;
        // In ra gia tri lon nhat cua mang
        case 3: 
            if(check == 0){
                printf("Xin hay nhap mang");
                break;
            }
            int max = arr[0];
            for(int i = 0; i < number; i++){
                if(max < arr[i]){
                    max = arr[i];
                }
            }
            printf("gia tri lon nhat cua mang la: %d", max);
            break;
        // In ra cac phan tu la so nguyen to cua mang
        case 4: 
            if(check == 0){
                    printf("Xin hay nhap mang");
                    break;
                }
            int coSoNguyenTo = 0;
            printf("so nguyen to trong mang la: ");
            for (int i = 0; i < number; i++){
                int checkSoNguyenTo = 1;
                if(arr[i] < 2){
                    checkSoNguyenTo = 0;
                } else {
                    for(int j = 2; j * j <= arr[i]; j++){
                        if(arr[i] % j == 0){
                            checkSoNguyenTo = 0;
                            break;
                        } 
                    }
                }
                if (checkSoNguyenTo == 1){
                    printf("%d ", arr[i]);
                    coSoNguyenTo = 1;
                }
            }
            if (coSoNguyenTo == 0){
                printf("\nkhong co so nguyen to");
            }
            break;
        // Them phan tu vao trong mang
        case 5: 
            if(check == 0){
                    printf("Xin hay nhap mang");
                    break;
            }
            int viTriThem, phanTuThem;
            printf("vi tri them phan tu la: ");
            scanf("%d", &viTriThem);
            if(viTriThem < 0 || viTriThem > number){
                printf("vi tri them khong hop le");
                break;
            }
            printf("hay nhap gia tri muon them: ");
            scanf("%d", &phanTuThem);
            for(int i = number; i >= viTriThem ; i--){
                arr[i + 1] = arr[i];
            }
            number++;
            arr[viTriThem] = phanTuThem;
            break;
        // Xoa mot phan tu trong mang  
        case 6: 
            if(check == 0){
                    printf("Xin hay nhap mang");
                    break;
            }
            int vitrixoa;
            printf("nhap vi tri can xoa: ");
            scanf("%d", &vitrixoa);
            if(vitrixoa < 0 || vitrixoa >= number){
                printf("vi tri xoa sai");
                break;
            }
            for(int i = vitrixoa; i < number; i++){
                arr[i] = arr[i+1];
            }
            number--;
            break;
		// Sap xep mang theo thu tu tang dan
        case 7: 
            if(check == 0){
                    printf("Xin hay nhap mang");
                    break;
            }
            int bienNho;
            for(int i  = 0; i < number; i++){
                for(int j = 0; j < number - 1 - i; j++){
                    if(arr[j] > arr[j + 1]){
                        bienNho = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = bienNho;
                    }
                }
            }
            printf("da sap xep");
            break;
        // Tim kiem phan tu va in ra vi tri cua no
        case 8: 
            if(check == 0){
                    printf("chua nhap mang");
                    break;
            }
			int phanTuTim;
            int found = 0;
            printf("Nhap phan tu de tim kiem: ");
            scanf("%d", &phanTuTim);
            printf("Vi tri phan tu o vi tri: ");
            for(int i = 0; i < number; i++){
                if(phanTuTim == arr[i]){
                    printf("%d", arr[i]);
                    found = 1;
                }
            }
            if(found == 0){
                printf("Khong tim thay phan tu do");
            }
        // Thoat khoi man hinh
		case 9: 
            return 0;
        default:
            printf("Khong hop le!.Vui long nhap lai");
        }

    }
    
    return 0;
}
