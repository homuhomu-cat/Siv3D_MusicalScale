# pragma once
# include <Siv3D.hpp>

//周波数
struct Freq
{
	double freq;

	Freq(long double freq) : freq(freq) {}

	double get()
	{
		return freq;
	}
};

//Hzリテラル
Freq operator"" _hz(unsigned long long int freq)
{
	return Freq((long double)freq);
}

//Hzリテラル
Freq operator"" _hz(long double freq)
{
	return Freq(freq);
}

//音階クラス
class Scale
{
private:
	//鍵盤番号
	int32 number;

public:
	//2の12乗根
	inline static const double TwelfthRootofTwo = Pow(2, 1.0 / 12);

	//基準周波数(A4)
	inline static constexpr double FreqA4 = 440.0;

	inline constexpr Scale() : number(0) {}

	inline constexpr Scale(int32 number) : number(number) {}

	Scale(Freq freq)
	{
		number = 49 + Round(Log(freq.get() / FreqA4) / Log(TwelfthRootofTwo));
	}

	//鍵盤番号を取得
	inline int32 getKeyNumber() const
	{
		return number;
	}

	//周波数を計算
	inline double getFreq() const
	{
		return FreqA4 * Pow(TwelfthRootofTwo, number - 49);
	}

	//絶対値
	inline int32 abs(Scale scale) const
	{
		return Abs(this->number - scale.number);
	}

	//音を生成
	inline Audio genAudio(Duration time = 1.0s, GMInstrument inst = GMInstrument::Piano1) const
	{
		return Audio(inst, static_cast<uint8>(number - 20), time);
	}

	//1音高くする
	inline auto& operator ++()
	{
		++number;
		return *this;
	}

	//1音高くする
	inline auto operator ++(int)
	{
		auto tmp = *this;
		++this->number;
		return tmp;
	}

	//1音低くする
	inline auto& operator --()
	{
		--number;
		return *this;
	}

	//1音低くする
	inline auto operator --(int)
	{
		auto tmp = *this;
		--this->number;
		return tmp;
	}

	//加算
	inline auto& operator +=(const Scale& scale)
	{
		this->number += scale.number;
		return *this;
	}

	//加算
	inline auto& operator +=(const int32 n)
	{
		this->number += n;
		return *this;
	}

	//減算
	inline auto& operator -=(const Scale& scale)
	{
		this->number -= scale.number;
		return *this;
	}

	//減算
	inline auto& operator -=(const int32 n)
	{
		this->number -= n;
		return *this;
	}

	//比較
	inline bool operator ==(const Scale& scale) const
	{
		return this->number == scale.number;
	}

	//比較
	inline bool operator !=(const Scale& scale) const
	{
		return !(*this == scale);
	}

	//比較
	inline bool operator >(const Scale& scale) const
	{
		return this->number > scale.number;
	}

	//比較
	inline bool operator <(const Scale & scale) const
	{
		return this->number < scale.number;
	}

	//比較
	inline bool operator >=(const Scale& scale) const
	{
		return this->number >= scale.number;
	}

	//比較
	inline bool operator <=(const Scale & scale) const
	{
		return this->number <= scale.number;
	}

	//オクターブ加算
	inline auto& operator <<(int32 n)
	{
		this->number += n * 12;
		return *this;
	}

	//オクターブ減算
	inline auto& operator >>(int32 n)
	{
		this->number -= n * 12;
		return *this;
	}
};

//ピアノ音階
namespace Sound
{
	inline constexpr Scale A0(1);
	inline constexpr Scale As0(2);
	inline constexpr Scale B0(3);

	inline constexpr Scale C1(4);
	inline constexpr Scale Cs1(5);
	inline constexpr Scale D1(6);
	inline constexpr Scale Ds1(7);
	inline constexpr Scale E1(8);
	inline constexpr Scale F1(9);
	inline constexpr Scale Fs1(10);
	inline constexpr Scale G1(11);
	inline constexpr Scale Gs1(12);
	inline constexpr Scale A1(13);
	inline constexpr Scale As1(14);
	inline constexpr Scale B1(15);

	inline constexpr Scale C2(16);
	inline constexpr Scale Cs2(17);
	inline constexpr Scale D2(18);
	inline constexpr Scale Ds2(19);
	inline constexpr Scale E2(20);
	inline constexpr Scale F2(21);
	inline constexpr Scale Fs2(22);
	inline constexpr Scale G2(23);
	inline constexpr Scale Gs2(24);
	inline constexpr Scale A2(25);
	inline constexpr Scale As2(26);
	inline constexpr Scale B2(27);

	inline constexpr Scale C3(28);
	inline constexpr Scale Cs3(29);
	inline constexpr Scale D3(30);
	inline constexpr Scale Ds3(31);
	inline constexpr Scale E3(32);
	inline constexpr Scale F3(33);
	inline constexpr Scale Fs3(34);
	inline constexpr Scale G3(35);
	inline constexpr Scale Gs3(36);
	inline constexpr Scale A3(37);
	inline constexpr Scale As3(38);
	inline constexpr Scale B3(39);

	inline constexpr Scale C4(40);
	inline constexpr Scale Cs4(41);
	inline constexpr Scale D4(42);
	inline constexpr Scale Ds4(43);
	inline constexpr Scale E4(44);
	inline constexpr Scale F4(45);
	inline constexpr Scale Fs4(46);
	inline constexpr Scale G4(47);
	inline constexpr Scale Gs4(48);
	inline constexpr Scale A4(49);
	inline constexpr Scale As4(50);
	inline constexpr Scale B4(51);

	inline constexpr Scale C5(52);
	inline constexpr Scale Cs5(53);
	inline constexpr Scale D5(54);
	inline constexpr Scale Ds5(55);
	inline constexpr Scale E5(56);
	inline constexpr Scale F5(57);
	inline constexpr Scale Fs5(58);
	inline constexpr Scale G5(59);
	inline constexpr Scale Gs5(60);
	inline constexpr Scale A5(61);
	inline constexpr Scale As5(62);
	inline constexpr Scale B5(63);

	inline constexpr Scale C6(64);
	inline constexpr Scale Cs6(65);
	inline constexpr Scale D6(66);
	inline constexpr Scale Ds6(67);
	inline constexpr Scale E6(68);
	inline constexpr Scale F6(69);
	inline constexpr Scale Fs6(70);
	inline constexpr Scale G6(71);
	inline constexpr Scale Gs6(72);
	inline constexpr Scale A6(73);
	inline constexpr Scale As6(74);
	inline constexpr Scale B6(75);

	inline constexpr Scale C7(76);
	inline constexpr Scale Cs7(77);
	inline constexpr Scale D7(78);
	inline constexpr Scale Ds7(79);
	inline constexpr Scale E7(80);
	inline constexpr Scale F7(81);
	inline constexpr Scale Fs7(82);
	inline constexpr Scale G7(83);
	inline constexpr Scale Gs7(84);
	inline constexpr Scale A7(85);
	inline constexpr Scale As7(86);
	inline constexpr Scale B7(87);

	inline constexpr Scale C8(88);
}
