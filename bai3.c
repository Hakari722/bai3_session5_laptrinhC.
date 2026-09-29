#include <stdio.h>

#define MAX 100
#define DON_GIA_GOC 150000L


long tinh_phi_kham(int co_bhyt) {
    if (co_bhyt == 1) {
        return DON_GIA_GOC * 20 / 100; 
    }
    return DON_GIA_GOC; 
}


void in_danh_sach(int ma_so[], int tuoi[], int co_bhyt[], int n) {
    if (n == 0) {
        printf("\nHang cho hien tai dang RONG!\n");
        return;
    }

    long tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("\n=======================================================================\n");
    printf("%-7s | %-12s | %-6s | %-12s | %-15s | %-10s\n", 
           "Index", "Ma So STT", "Tuoi", "BHYT", "Tien Kham (VND)", "Doi Tuong");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        long tien_kham = tinh_phi_kham(co_bhyt[i]);
        tong_doanh_thu += tien_kham;

        char *str_bhyt = (co_bhyt[i] == 1) ? "Co BHYT" : "Khong BHYT";
        char *str_uu_tien = (tuoi[i] >= 70) ? "UU TIEN" : "Thuong";

        if (tuoi[i] >= 70) {
            so_ca_uu_tien++;
        }

        printf("%-7d | %-12d | %-6d | %-12s | %-15ld | %-10s\n", 
               i, ma_so[i], tuoi[i], str_bhyt, tien_kham, str_uu_tien);
    }

    printf("=======================================================================\n");
    printf("-> Tong doanh thu du kien : %ld VND\n", tong_doanh_thu);
    printf("-> So luong benh nhan UU TIEN: %d\n", so_ca_uu_tien);
    printf("=======================================================================\n");
}

int main() {
  
    int ma_so[MAX];
    int tuoi[MAX];
    int co_bhyt[MAX];
    int n = 0;

    printf("=== HE THONG KIOSK QUAN LY HANG CHO PHONG KHAM MEDICARE ===\n");


    do {
        printf("Nhap so luong benh nhan dang ky ban dau (0 <= n <= %d): ", MAX);
        scanf("%d", &n);
        if (n < 0 || n > MAX) {
            printf("[LOI] So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin Benh nhan thu %d (Index %d) ---\n", i + 1, i);
        
        ma_so[i] = 1001 + i; 

    
        do {
            printf("Nhap tuoi (1 - 120): ");
            scanf("%d", &tuoi[i]);
            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("[LOI] Tuoi khong hop le! Yeu cau nhap trong khoang 1 - 120.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Trang thai BHYT (1: Co, 0: Khong): ");
            scanf("%d", &co_bhyt[i]);
            if (co_bhyt[i] != 0 && co_bhyt[i] != 1) {
                printf("[LOI] Trang thai BHYT chi nhan 0 hoac 1! Vui long nhap lai.\n");
            }
        } while (co_bhyt[i] != 0 && co_bhyt[i] != 1);
    }

    printf("\n>>> DANH SACH HANG CHO BAN DAU <<<");
    in_danh_sach(ma_so, tuoi, co_bhyt, n);

    if (n == 0) {
        printf("\nHang cho rong, khong the thuc hien thao tac huy.\n");
        return 0;
    }

    int K;
    printf("\n>>> THUC HIEN NG HIEP VU HUY LUOT KHAM <<<\n");
    printf("Nhap chi so (Index K) cua benh nhan muon huy (0 <= K < %d): ", n);
    scanf("%d", &K);

    if (K < 0 || K >= n) {
        printf("\n[LOI] Chi so K = %d KHONG HOP LE! Thao tac huy bi tu choi.\n", K);
    } else {
        printf("\n[XAC NHAN] Dang huy luot kham cua Benh nhan Ma so %d tai Index %d...\n", ma_so[K], K);
        for (int i = K; i < n - 1; i++) {
            ma_so[i] = ma_so[i + 1];
            tuoi[i] = tuoi[i + 1];
            co_bhyt[i] = co_bhyt[i + 1];
        }

        n--;

        printf("[THANH CONG] Da cap nhat lai hang cho va loai bo du lieu rac!\n");

        printf("\n>>> DANH SACH HANG CHO SAU KHI HUY (TAI CAU TRUC) <<<");
        in_danh_sach(ma_so, tuoi, co_bhyt, n);
    }

    return 0;
}