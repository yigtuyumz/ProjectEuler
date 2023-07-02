#include <stdio.h>
#include <pthread.h>

#define LIMIT 2000000
#define NUM_THREADS 8

/*
 * Her bir thread bir aralikta calisir.
 * Bu aralik, limit degerinin thread sayisina bolumu ile elde edilir.
 * Butun thread'ler araligi limit degerine kadar esit bir sekilde boluserek
 * her thread'in ayni degerei handle etmesi saglanir.
 */

/*
 * Bu struct, multithread fonksiyonlara birden fazla arguman gonderilemedigi icin
 * olusturulur. Struct tek bir veri tipi oldugundan, icerisine ihtiyac duyulan
 * parametrelerin hepsi yerlestirilerek butun bu verinin tek bir veri
 * olmasi saglanir.
 */
typedef struct thread_data_s {
	/* araligin baslangic degeri */
	unsigned long int start;
	/* araligin bitis degeri */
	unsigned long int end;
	/* her bir thread'in return degeri */
	unsigned long int sum;
} thread_data_t;

/*
 * Asal sayi hesabi icin 6k+-1 teoreminden faydalanilarak olusturulan
 * asal sayi fonksiyonu. Fonksiyon, nb asal ise 1 degil ise 0 degerini dondurur.
 */
unsigned long int is_prime(unsigned long int nb)
{
	/*
	 * 6 dan onceki degerleri ayri ayri kontrol ediyoruz.
	 * En kucuk asal sayi 2'dir.
	 */
	if (nb <= 1) {
		return (0);
	}

	/* yukaridaki kosula dusmemisse ve sayi <= 3 ise */
	if (nb <= 3) {
		return (1);
	}

	/*
	 * Sayi 2 nin veya 3 un kati ise asal degildir. sayi 3 ise yukaridaki
	 * kosuldan dolayi fonksiyon 1 return edecegi icin buraya dusmeyecektir.
	 */
	if (nb % 2 == 0 || nb % 3 == 0) {
		return (0);
	}

	/*
	 * Bu for dongusunu 25 ve 25'ten buyuk sayilar icin kullaniyoruz cunku
	 * 25'ten kucuk butun sayilarin asal olup olmadigin yukaridaki kosullar ile
	 * denetleyebiliyoruz. i degerini her bir dongude 6 arttiriyoruz cunku
	 * teoremdeki formulde k'nin (degisken) katsayisi 6 oldugu icin.
	 * (dongudeki i, formuldeki k gibi dusunulebilinir.)
	 */
	for (unsigned long int i = 5; i * i <= nb; i += 6) {
		if (nb % i == 0 || nb % (i + 2) == 0) {
			return (0);
		}
	}
	return (1);
}

/*
 * Her bir thread'in calistiracagi fonksiyon.
 * Fonksiyon tipinin ve parametrenin void pointer olmasi, herhangi bir veri
 * olabilecegi anlamina gelir.
 */
void *thread_task(void *argp)
{
	/*
	 * argumanimizi verimizin tipine typecast ediyoruz.
	 * bir pointer'a typecast etmemizin sebebi fonksiyonun disarisindaki
	 * adreslere erisme gerekliligi oldugundandir. (struct'un icerisindeki
	 * her bir veri'ye erismek vs.)
	 */
	thread_data_t *data = (thread_data_t *) argp;

	/* fonksiyonumuzun disariya gonderecegi deger. */
	unsigned long int sum = 0;

	/* araliktaki sayilarin hepsinin asal olup olmadigini kontrol ediyoruz. */
	for (unsigned long int curr_num = data->start; curr_num <= data->end;
	     curr_num++) {
		if (is_prime(curr_num)) {
			sum += curr_num;
		}
	}
	data->sum = sum;
	return (NULL);
}

int main(void)
{
	/* her bir thread'in araligi. */
	unsigned long int range = LIMIT / NUM_THREADS;

	/* thread'leri aciyoruz. */
	pthread_t thread_ids[NUM_THREADS];
	/* her bir thread'imizin sahip olacagi aralik ve veri icin struct set'liyoruz. */
	thread_data_t thread_arg_arr[NUM_THREADS];

	/*
	 * Bu for dongusunde, her bir thread'in sahip oldugu araligin baslangic ve
	 * bitis degerlerini ayarliyoruz. Ancak bu dongu son thread haric olacak sekilde
	 * diger butun thread'leri set'ler. Cunku son thread'in end degeri basitce
	 * limit'e esit olur.
	 */
	for (unsigned long int i = 0; i < NUM_THREADS; i++) {
		/* 
		 * +1 eklemememizin sebebi, bir onceki thread'in end degerine iki kez
		 * erismemek icin.
		 */
		thread_arg_arr[i].start = i * range + 1;
		/*
		 * Buradaki +1 ise, i sifir iken end degerinin ust noktayi isaret etmesini
		 * istedigimiz icin.
		 */
		thread_arg_arr[i].end = (i + 1) * range;
	}
	/* son thread'in end'ini set'liyoruz. */
	thread_arg_arr[NUM_THREADS - 1].end = LIMIT;

	/* thread'leri olusturuyoruz. */
	for (unsigned long int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&thread_ids[i], NULL, thread_task,
			       (void *)&thread_arg_arr[i]);
	}

	/* thread'leri join'liyoruz. (tamamlanmasini bekliyoruz.) */
	for (unsigned long int i = 0; i < NUM_THREADS; i++) {
		pthread_join(thread_ids[i], NULL);
	}

	/*
	 * Bu noktada her bir thread sum degerini elde etti.
	 * Ana cevap icin butun sum degerlerini topluyoruz.
	 */

	unsigned long int answer = 0;

	for (unsigned long int i = 0; i < NUM_THREADS; i++) {
		answer += thread_arg_arr[i].sum;
	}

	printf("%lu\n", answer);
	return (0);
}
