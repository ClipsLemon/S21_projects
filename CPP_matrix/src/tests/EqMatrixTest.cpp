#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(EqMatrix, equal1) {
  S21Matrix object(1, 1);
  double **matrix = object.GetMatrix();

  matrix[0][0] = 2562.9356782;

  S21Matrix object2(object);

  EXPECT_TRUE(object.EqMatrix(object2));
}

TEST(EqMatrix, equal2) {
  S21Matrix object(2, 2);
  double **matrix = object.GetMatrix();

  matrix[0][0] = 2562.9356782;
  matrix[0][1] = 13.8239483;
  matrix[1][0] = -18283.9992223;
  matrix[1][1] = 67292113.8234499;

  S21Matrix object2(object);

  EXPECT_TRUE(object.EqMatrix(object2));
}

TEST(EqMatrix, equal3) {
  S21Matrix object(3, 3);
  double **matrix = object.GetMatrix();

  matrix[0][0] = 7882270.7500668;
  matrix[0][1] = 20538121.4107794;
  matrix[0][2] = 9186906.4110952;
  matrix[1][0] = -15209422.6197869;
  matrix[1][1] = 1610983.561664;
  matrix[1][2] = -16840028.5260783;
  matrix[2][0] = 21341743.9627965;
  matrix[2][1] = 19050226.3908237;
  matrix[2][2] = -8483277.4959925;

  S21Matrix object2(object);

  EXPECT_TRUE(object.EqMatrix(object2));
}

TEST(EqMatrix, equal4) {
  S21Matrix object1(4, 4);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 6168587.8795401;
  matrix1[0][1] = 9490539.1799354;
  matrix1[0][2] = 7385936.2053389;
  matrix1[0][3] = 810354.2305386;
  matrix1[1][0] = -20781524.4589037;
  matrix1[1][1] = 13198180.5447793;
  matrix1[1][2] = 2151140.1811052;
  matrix1[1][3] = -1333561.7180129;
  matrix1[2][0] = 13459672.2492238;
  matrix1[2][1] = 2276862.4228489;
  matrix1[2][2] = -18197803.5917448;
  matrix1[2][3] = 3633139.8533066;
  matrix1[3][0] = 18650806.6238704;
  matrix1[3][1] = 19176827.683023;
  matrix1[3][2] = -9608548.5817267;
  matrix1[3][3] = 6355975.5633537;

  S21Matrix object2(object1);

  EXPECT_TRUE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal5) {
  S21Matrix object1(5, 5);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = -1783353.3481714;
  matrix1[0][1] = 5949694.3655626;
  matrix1[0][2] = 4887844.8783063;
  matrix1[0][3] = -6267260.9323816;
  matrix1[0][4] = 12596464.1306498;
  matrix1[1][0] = 13190648.8962661;
  matrix1[1][1] = 16780158.6707789;
  matrix1[1][2] = -11318119.7835420;
  matrix1[1][3] = 20537085.3394906;
  matrix1[1][4] = 9726194.4213515;
  matrix1[2][0] = 5537504.4954002;
  matrix1[2][1] = 15883955.5915182;
  matrix1[2][2] = -4513788.4167812;
  matrix1[2][3] = 11325549.9633416;
  matrix1[2][4] = 5035760.1850037;
  matrix1[3][0] = 11380942.6084540;
  matrix1[3][1] = 3949212.5616085;
  matrix1[3][2] = 1886651.5771939;
  matrix1[3][3] = 3207116.8041453;
  matrix1[3][4] = 8146976.3273915;
  matrix1[4][0] = 21443593.8449531;
  matrix1[4][1] = 4144355.4170468;
  matrix1[4][2] = -21414730.9532100;
  matrix1[4][3] = 8106352.3580197;
  matrix1[4][4] = 15627344.5857585;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = -1783353.3481714;
  matrix2[0][1] = 5949694.3655626;
  matrix2[0][2] = 4887844.8783063;
  matrix2[0][3] = -6267260.9323816;
  matrix2[0][4] = 12596464.1306498;
  matrix2[1][0] = 13190648.8962661;
  matrix2[1][1] = 16780158.6707789;
  matrix2[1][2] = -11318119.7835420;
  matrix2[1][3] = 20537085.3394906;
  matrix2[1][4] = 9726194.4213515;
  matrix2[2][0] = 5537504.4954002;
  matrix2[2][1] = 15883955.5915182;
  matrix2[2][2] = -4513788.4167812;
  matrix2[2][3] = 11325549.9633416;
  matrix2[2][4] = 5035760.1850038;
  matrix2[3][0] = 11380942.6084540;
  matrix2[3][1] = 3949212.5616085;
  matrix2[3][2] = 1886651.5771939;
  matrix2[3][3] = 3207116.8041453;
  matrix2[3][4] = 8146976.3273915;
  matrix2[4][0] = 21443593.8449531;
  matrix2[4][1] = 4144355.4170468;
  matrix2[4][2] = -21414730.9532100;
  matrix2[4][3] = 8106352.3580197;
  matrix2[4][4] = 15627344.5857585;

  EXPECT_FALSE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal6) {
  S21Matrix object1(6, 6);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 3810.9392097;
  matrix1[0][1] = 8868787.6238781;
  matrix1[0][2] = 391125.3086098;
  matrix1[0][3] = 14583688.359796;
  matrix1[1][0] = -20138658.3130406;
  matrix1[1][1] = 10036744.3430184;
  matrix1[1][2] = 44274.8687072;
  matrix1[1][3] = 6935150.9654492;
  matrix1[2][0] = 4983329.2670433;
  matrix1[2][1] = 10350327.4991315;
  matrix1[2][2] = 11282791.5471000;
  matrix1[2][3] = -16493302.1031996;
  matrix1[3][0] = 7955580.322021;
  matrix1[3][1] = 8101264.324564;
  matrix1[3][2] = -2542153.6531694;
  matrix1[3][3] = 19787038.153998;
  matrix1[4][0] = 12737872.2978265;
  matrix1[4][1] = 870920.4668998;
  matrix1[4][2] = 11664469.2938944;
  matrix1[4][3] = -15330679.3808275;
  matrix1[5][0] = 7178352.5822452;
  matrix1[5][1] = -15872576.5739776;
  matrix1[5][2] = 5934682.7655349;
  matrix1[5][3] = 6373185.903538;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = 3810.9392097;
  matrix2[0][1] = 8868787.6238781;
  matrix2[0][2] = 391125.3086098;
  matrix2[0][3] = 14583688.359796;
  matrix2[1][0] = -20138658.3130406;
  matrix2[1][1] = 10036744.3430184;
  matrix2[1][2] = 44274.8687072;
  matrix2[1][3] = 6935150.9654492;
  matrix2[2][0] = 4983329.2670433;
  matrix2[2][1] = 10350327.4991315;
  matrix2[2][2] = 11282791.5471000;
  matrix2[2][3] = -16493302.1031996;
  matrix2[3][0] = 7955580.322021;
  matrix2[3][1] = 8101264.324564;
  matrix2[3][2] = -2542153.6531694;
  matrix2[3][3] = 19787038.153998;
  matrix2[4][0] = 12737872.2978265;
  matrix2[4][1] = 870920.4668998;
  matrix2[4][2] = 11664469.2938944;
  matrix2[4][3] = -15330679.3808275;
  matrix2[5][0] = 7178352.5822452;
  matrix2[5][1] = -15872576.5739776;
  matrix2[5][2] = 5934682.7655349;
  matrix2[5][3] = 6373185.903538;

  EXPECT_TRUE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal7) {
  S21Matrix object1(7, 7);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 5734816.3244692;
  matrix1[0][1] = 474432.4310587;
  matrix1[0][2] = 19309055.8195260;
  matrix1[0][3] = 787678.9802777;
  matrix1[0][4] = -5411481.2045629;
  matrix1[0][5] = 5652568.4291437;
  matrix1[0][6] = -16632411.4699782;
  matrix1[1][0] = 355790.9012341;
  matrix1[1][1] = 3666881.8436793;
  matrix1[1][2] = 8234668.8879250;
  matrix1[1][3] = -14584787.1182827;
  matrix1[1][4] = 5971048.5700655;
  matrix1[1][5] = 2353096.9120503;
  matrix1[1][6] = -7771635.3730176;
  matrix1[2][0] = 6679967.4162318;
  matrix1[2][1] = 21048038.9407823;
  matrix1[2][2] = 20549074.8003422;
  matrix1[2][3] = -8599344.7985539;
  matrix1[2][4] = 16978281.1266354;
  matrix1[2][5] = 14943927.6851149;
  matrix1[2][6] = 3321337.480630;
  matrix1[3][0] = 13935190.2654359;
  matrix1[3][1] = -12552746.4767776;
  matrix1[3][2] = 8153611.3149187;
  matrix1[3][3] = 5452173.7058611;
  matrix1[3][4] = 8639641.133370;
  matrix1[3][5] = 11783627.3175455;
  matrix1[3][6] = 9394933.2123688;
  matrix1[4][0] = -11179553.7475989;
  matrix1[4][1] = 11434102.961410;
  matrix1[4][2] = 15997476.3868281;
  matrix1[4][3] = 9819732.3331131;
  matrix1[4][4] = 11431045.3034917;
  matrix1[4][5] = 8606548.442110;
  matrix1[4][6] = 3463516.5809226;
  matrix1[5][0] = 12492510.8571818;
  matrix1[5][1] = 18219056.3750263;
  matrix1[5][2] = 9135348.7153266;
  matrix1[5][3] = -7714093.2558042;
  matrix1[5][4] = 21153294.5158272;
  matrix1[5][5] = -18963582.1953004;
  matrix1[5][6] = 20420983.818894;
  matrix1[6][0] = 12419663.4454880;
  matrix1[6][1] = 10745296.1338698;
  matrix1[6][2] = 4357920.8531296;
  matrix1[6][3] = 21009745.9281348;
  matrix1[6][4] = 8896329.7690860;
  matrix1[6][5] = -1565752.2339452;
  matrix1[6][6] = 21032185.3749147;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = 5734816.3244692;
  matrix2[0][1] = 474432.4310587;
  matrix2[0][2] = 19309055.8195260;
  matrix2[0][3] = 787678.9802777;
  matrix2[0][4] = -5411481.2045629;
  matrix2[0][5] = 5652568.4291437;
  matrix2[0][6] = -16632411.4699782;
  matrix2[1][0] = 355790.9012341;
  matrix2[1][1] = 3666881.8436793;
  matrix2[1][2] = 8234668.8879250;
  matrix2[1][3] = -14584787.1182827;
  matrix2[1][4] = 5971048.5700655;
  matrix2[1][5] = 2353096.9120503;
  matrix2[1][6] = -7771635.3730176;
  matrix2[2][0] = 6679967.4162318;
  matrix2[2][1] = 21048038.9407823;
  matrix2[2][2] = 20549074.8003422;
  matrix2[2][3] = -8599344.7985539;
  matrix2[2][4] = 16978281.1266354;
  matrix2[2][5] = 14943927.6851149;
  matrix2[2][6] = 3321337.480630;
  matrix2[3][0] = 13935190.2654359;
  matrix2[3][1] = -12552746.4767776;
  matrix2[3][2] = 8153611.3149187;
  matrix2[3][3] = 5452173.7058611;
  matrix2[3][4] = 8639641.133370;
  matrix2[3][5] = 11783627.3175455;
  matrix2[3][6] = 9394933.2123688;
  matrix2[4][0] = -11179553.7475989;
  matrix2[4][1] = 11434102.961410;
  matrix2[4][2] = 15997476.3868281;
  matrix2[4][3] = 9819732.3331131;
  matrix2[4][4] = 11431045.3034917;
  matrix2[4][5] = 8606548.442110;
  matrix2[4][6] = 3463516.5809226;
  matrix2[5][0] = 12492510.8571818;
  matrix2[5][1] = 18219056.3750263;
  matrix2[5][2] = 9135348.7153266;
  matrix2[5][3] = -7714093.2558042;
  matrix2[5][4] = 21153294.5158272;
  matrix2[5][5] = -18963582.1953004;
  matrix2[5][6] = 20420983.818894;
  matrix2[6][0] = 12419663.4454880;
  matrix2[6][1] = 10745296.1338698;
  matrix2[6][2] = 4357920.8531296;
  matrix2[6][3] = 21009745.9281348;
  matrix2[6][4] = 8896329.7690860;
  matrix2[6][5] = -1565752.2339452;
  matrix2[6][6] = 21032185.3749147;

  EXPECT_TRUE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal8) {
  S21Matrix object1(8, 8);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 17929262.4632594;
  matrix1[0][1] = -1416693.5377523;
  matrix1[0][2] = 12725927.5434423;
  matrix1[0][3] = 11603708.3732249;
  matrix1[0][4] = 2919061.9936115;
  matrix1[0][5] = -3113592.3372770;
  matrix1[0][6] = 1159495.973396;
  matrix1[0][7] = 572131.495275;
  matrix1[1][0] = 316777.4632862;
  matrix1[1][1] = 9613222.5352120;
  matrix1[1][2] = -17817566.4672516;
  matrix1[1][3] = 15213351.2112044;
  matrix1[1][4] = 4716429.8052024;
  matrix1[1][5] = 11409071.1915079;
  matrix1[1][6] = 19188774.394418;
  matrix1[1][7] = 16231072.8514334;
  matrix1[2][0] = 5440940.2740038;
  matrix1[2][1] = -14904632.8898624;
  matrix1[2][2] = 18017666.1805501;
  matrix1[2][3] = -15281537.4789312;
  matrix1[2][4] = 14281213.3965229;
  matrix1[2][5] = 10583962.5637559;
  matrix1[2][6] = 18873237.3517146;
  matrix1[2][7] = 13123444.4568586;
  matrix1[3][0] = -18061787.9778773;
  matrix1[3][1] = 1722285.8398009;
  matrix1[3][2] = 10525604.401669;
  matrix1[3][3] = -5680725.8867641;
  matrix1[3][4] = 17435949.2009339;
  matrix1[3][5] = 15117247.8598677;
  matrix1[3][6] = 4572335.4051158;
  matrix1[3][7] = 3723932.4335160;
  matrix1[4][0] = 2327730.3773325;
  matrix1[4][1] = 20325359.6684335;
  matrix1[4][2] = 19050528.4846356;
  matrix1[4][3] = -12139693.3205487;
  matrix1[4][4] = 21420965.1297627;
  matrix1[4][5] = 8653105.3447402;
  matrix1[4][6] = -5876575.1181661;
  matrix1[4][7] = 20418506.7310753;
  matrix1[5][0] = 7722635.7210357;
  matrix1[5][1] = 11105161.5732355;
  matrix1[5][2] = 13328979.2854828;
  matrix1[5][3] = 1867541.3622933;
  matrix1[5][4] = 18891035.8386415;
  matrix1[5][5] = 9273970.198877;
  matrix1[5][6] = -10206504.9820385;
  matrix1[5][7] = 7420596.2485816;
  matrix1[6][0] = -21318669.6568807;
  matrix1[6][1] = 18527192.8897392;
  matrix1[6][2] = 11913837.1975665;
  matrix1[6][3] = -10121431.8499248;
  matrix1[6][4] = 3395431.7126887;
  matrix1[6][5] = 14817502.4984814;
  matrix1[6][6] = 3045972.1664041;
  matrix1[6][7] = 4462912.6259167;
  matrix1[7][0] = -8826373.1837849;
  matrix1[7][1] = 4367105.9275112;
  matrix1[7][2] = 937708.6606937;
  matrix1[7][3] = 6080163.3386161;
  matrix1[7][4] = 6953419.3293762;
  matrix1[7][5] = -4662356.4051529;
  matrix1[7][6] = 13403031.6252811;
  matrix1[7][7] = 11892348.6241847;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = 17929262.463259465666;
  matrix2[0][1] = -1416693.5377523;
  matrix2[0][2] = 12725927.5434423;
  matrix2[0][3] = 11603708.3732249;
  matrix2[0][4] = 2919061.9936115;
  matrix2[0][5] = -3113592.33727707465;
  matrix2[0][6] = 1159495.973396;
  matrix2[0][7] = 572131.495275;
  matrix2[1][0] = 316777.4632862;
  matrix2[1][1] = 9613222.5352120;
  matrix2[1][2] = -17817566.4672516;
  matrix2[1][3] = 15213351.2112044;
  matrix2[1][4] = 4716429.8052024;
  matrix2[1][5] = 11409071.1915079;
  matrix2[1][6] = 19188774.394418;
  matrix2[1][7] = 16231072.8514334;
  matrix2[2][0] = 5440940.2740038;
  matrix2[2][1] = -14904632.8898624;
  matrix2[2][2] = 18017666.1805501;
  matrix2[2][3] = -15281537.4789312987;
  matrix2[2][4] = 14281213.3965229;
  matrix2[2][5] = 10583962.5637559;
  matrix2[2][6] = 18873237.3517146;
  matrix2[2][7] = 13123444.4568586;
  matrix2[3][0] = -18061787.9778773;
  matrix2[3][1] = 1722285.8398009;
  matrix2[3][2] = 10525604.401669;
  matrix2[3][3] = -5680725.8867641;
  matrix2[3][4] = 17435949.2009339;
  matrix2[3][5] = 15117247.8598677;
  matrix2[3][6] = 4572335.4051158;
  matrix2[3][7] = 3723932.4335160;
  matrix2[4][0] = 2327730.3773325;
  matrix2[4][1] = 20325359.6684335;
  matrix2[4][2] = 19050528.4846356;
  matrix2[4][3] = -12139693.32054879778956;
  matrix2[4][4] = 21420965.1297627;
  matrix2[4][5] = 8653105.3447402;
  matrix2[4][6] = -5876575.1181661;
  matrix2[4][7] = 20418506.7310753;
  matrix2[5][0] = 7722635.7210357;
  matrix2[5][1] = 11105161.5732355;
  matrix2[5][2] = 13328979.2854828;
  matrix2[5][3] = 1867541.3622933;
  matrix2[5][4] = 18891035.8386415;
  matrix2[5][5] = 9273970.198877;
  matrix2[5][6] = -10206504.9820385386;
  matrix2[5][7] = 7420596.2485816;
  matrix2[6][0] = -21318669.6568807;
  matrix2[6][1] = 18527192.8897392;
  matrix2[6][2] = 11913837.1975665;
  matrix2[6][3] = -10121431.8499248;
  matrix2[6][4] = 3395431.7126887;
  matrix2[6][5] = 14817502.4984814;
  matrix2[6][6] = 3045972.1664041087578;
  matrix2[6][7] = 4462912.6259167;
  matrix2[7][0] = -8826373.1837849;
  matrix2[7][1] = 4367105.9275112;
  matrix2[7][2] = 937708.6606937;
  matrix2[7][3] = 6080163.3386161;
  matrix2[7][4] = 6953419.3293762;
  matrix2[7][5] = -4662356.4051529;
  matrix2[7][6] = 13403031.6252811;
  matrix2[7][7] = 11892348.6241847;

  EXPECT_TRUE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal9) {
  S21Matrix object1(9, 9);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 9761923.325333;
  matrix1[0][1] = 16233102.1727590;
  matrix1[0][2] = 5774196.8710521;
  matrix1[0][3] = 16597051.1307990;
  matrix1[0][4] = -13102872.9121109;
  matrix1[0][5] = 15487866.5715667;
  matrix1[0][6] = 6500428.2646572;
  matrix1[0][7] = -18281884.2206019;
  matrix1[0][8] = 2783916.2143021;
  matrix1[1][0] = 6997996.7697970;
  matrix1[1][1] = 16129538.4856363;
  matrix1[1][2] = 12351232.951088;
  matrix1[1][3] = -9169044.8857404;
  matrix1[1][4] = 2710342.3114909;
  matrix1[1][5] = 20736396.9014253;
  matrix1[1][6] = -7744220.7558244;
  matrix1[1][7] = 10938862.6287175;
  matrix1[1][8] = -2273770.494436;
  matrix1[2][0] = 12022321.7265453;
  matrix1[2][1] = 6626108.7156246;
  matrix1[2][2] = -1041058.7284414;
  matrix1[2][3] = 15264275.3174780;
  matrix1[2][4] = 3998555.3006433;
  matrix1[2][5] = -571486.9935329;
  matrix1[2][6] = 14059035.3271502;
  matrix1[2][7] = 14249679.7706588;
  matrix1[2][8] = 6547807.9105794;
  matrix1[3][0] = 15007421.906040;
  matrix1[3][1] = -12817021.989484;
  matrix1[3][2] = 7434254.3398746;
  matrix1[3][3] = 6856458.3657629;
  matrix1[3][4] = -4023795.9740667;
  matrix1[3][5] = 7916323.2498183;
  matrix1[3][6] = 10527442.1295746;
  matrix1[3][7] = 6984766.7794900;
  matrix1[3][8] = 17816366.4735726;
  matrix1[4][0] = -13732884.669773;
  matrix1[4][1] = 4657970.211583;
  matrix1[4][2] = -15133217.9337039;
  matrix1[4][3] = 7596861.8140658;
  matrix1[4][4] = 2522606.4271915;
  matrix1[4][5] = -21473745.5368942;
  matrix1[4][6] = 1062624.5921858;
  matrix1[4][7] = 18482400.1692040;
  matrix1[4][8] = 10424667.2612002;
  matrix1[5][0] = 4097218.8419595;
  matrix1[5][1] = -17396426.6204771;
  matrix1[5][2] = 15017547.16252;
  matrix1[5][3] = 3762425.8286052;
  matrix1[5][4] = -20863322.7740147;
  matrix1[5][5] = 12340605.2712864;
  matrix1[5][6] = 13905481.5148916;
  matrix1[5][7] = -20525312.2149211;
  matrix1[5][8] = 2022389.3958514;
  matrix1[6][0] = -2813917.4220333;
  matrix1[6][1] = 10612834.2020357;
  matrix1[6][2] = 4355387.6593581;
  matrix1[6][3] = -1904767.2751524;
  matrix1[6][4] = 2446436.5432209;
  matrix1[6][5] = -20604133.3297039;
  matrix1[6][6] = 19098567.243244;
  matrix1[6][7] = 1789654.1011170;
  matrix1[6][8] = -17185070.8450477;
  matrix1[7][0] = 13614212.6142932;
  matrix1[7][1] = 15675060.3583534;
  matrix1[7][2] = -5681306.1251609;
  matrix1[7][3] = 12966522.6560955;
  matrix1[7][4] = -11807466.7988719;
  matrix1[7][5] = 9867653.6902186;
  matrix1[7][6] = 6996499.1177718;
  matrix1[7][7] = -7259497.6451139;
  matrix1[7][8] = 17004770.8015045;
  matrix1[8][0] = 14548213.5611422;
  matrix1[8][1] = -14008296.9754671;
  matrix1[8][2] = 20849520.6923683;
  matrix1[8][3] = -19140186.1729922;
  matrix1[8][4] = 4729061.9374256;
  matrix1[8][5] = 803723.1278040;
  matrix1[8][6] = -21180304.2399553;
  matrix1[8][7] = 20596065.5153442;
  matrix1[8][8] = 11047593.3123617;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = 9761923.325333;
  matrix2[0][1] = 16233102.1727590;
  matrix2[0][2] = 5774196.8710521;
  matrix2[0][3] = 16597051.1307990;
  matrix2[0][4] = -13102872.9121109;
  matrix2[0][5] = 15487866.5715667;
  matrix2[0][6] = 6500428.2646572;
  matrix2[0][7] = -18281884.2206019;
  matrix2[0][8] = 2783916.2143021;
  matrix2[1][0] = 6997996.7697970;
  matrix2[1][1] = 16129538.4856363;
  matrix2[1][2] = 12351232.951088;
  matrix2[1][3] = -9169044.8857404;
  matrix2[1][4] = 2710342.3114909;
  matrix2[1][5] = 20736396.9014253;
  matrix2[1][6] = -7744220.7558244;
  matrix2[1][7] = 10938862.6287175;
  matrix2[1][8] = -2273770.494436;
  matrix2[2][0] = 12022321.7265453;
  matrix2[2][1] = 6626108.7156246;
  matrix2[2][2] = -1041058.7284414;
  matrix2[2][3] = 15264275.3174780;
  matrix2[2][4] = 3998555.3006433;
  matrix2[2][5] = -571486.9935329;
  matrix2[2][6] = 14059035.3271502;
  matrix2[2][7] = 14249679.7706588;
  matrix2[2][8] = 6547807.9105794;
  matrix2[3][0] = 15007421.906040;
  matrix2[3][1] = -12817021.9894831;
  matrix2[3][2] = 7434254.3398746;
  matrix2[3][3] = 6856458.3657629;
  matrix2[3][4] = -4023795.9740667;
  matrix2[3][5] = 7916323.2498183;
  matrix2[3][6] = 10527442.1295746;
  matrix2[3][7] = 6984766.7794900;
  matrix2[3][8] = 17816366.4735726;
  matrix2[4][0] = -13732884.669773;
  matrix2[4][1] = 4657970.211583;
  matrix2[4][2] = -15133217.9337039;
  matrix2[4][3] = 7596861.8140658;
  matrix2[4][4] = 2522606.4271915;
  matrix2[4][5] = -21473745.5368942;
  matrix2[4][6] = 1062624.5921858;
  matrix2[4][7] = 18482400.1692040;
  matrix2[4][8] = 10424667.2612002;
  matrix2[5][0] = 4097218.8419595;
  matrix2[5][1] = -17396426.6204771;
  matrix2[5][2] = 15017547.16252;
  matrix2[5][3] = 3762425.8286052;
  matrix2[5][4] = -20863322.7740147;
  matrix2[5][5] = 12340605.2712864;
  matrix2[5][6] = 13905481.5148916;
  matrix2[5][7] = -20525312.2149211;
  matrix2[5][8] = 2022389.3958514;
  matrix2[6][0] = -2813917.4220333;
  matrix2[6][1] = 10612834.2020357;
  matrix2[6][2] = 4355387.6593581;
  matrix2[6][3] = -1904767.2751524;
  matrix2[6][4] = 2446436.5432209;
  matrix2[6][5] = -20604133.3297039;
  matrix2[6][6] = 19098567.243244;
  matrix2[6][7] = 1789654.1011170;
  matrix2[6][8] = -17185070.8450477;
  matrix2[7][0] = 13614212.6142932;
  matrix2[7][1] = 15675060.3583534;
  matrix2[7][2] = -5681306.1251609;
  matrix2[7][3] = 12966522.6560955;
  matrix2[7][4] = -11807466.7988719;
  matrix2[7][5] = 9867653.6902186;
  matrix2[7][6] = 6996499.1177718;
  matrix2[7][7] = -7259497.6451139;
  matrix2[7][8] = 17004770.8015045;
  matrix2[8][0] = 14548213.5611422;
  matrix2[8][1] = -14008296.9754671;
  matrix2[8][2] = 20849520.6923683;
  matrix2[8][3] = -19140186.1729922;
  matrix2[8][4] = 4729061.9374256;
  matrix2[8][5] = 803723.1278040;
  matrix2[8][6] = -21180304.2399553;
  matrix2[8][7] = 20596065.5153442;
  matrix2[8][8] = 11047593.3123617;

  EXPECT_FALSE(object1.EqMatrix(object2));
}

TEST(EqMatrix, equal10) {
  S21Matrix object1(10, 10);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = 1060648.9269141;
  matrix1[0][1] = 13111258.6690684;
  matrix1[0][2] = 14965626.1121514;
  matrix1[0][3] = 17211605.2262267;
  matrix1[0][4] = -7589837.1912895;
  matrix1[0][5] = 20837462.4689637;
  matrix1[0][6] = 5667759.5596447;
  matrix1[0][7] = 5434453.6500901;
  matrix1[0][8] = 10296482.9252318;
  matrix1[0][9] = -15968188.3369038;
  matrix1[1][0] = 6578356.7948861;
  matrix1[1][1] = -16264987.8245067;
  matrix1[1][2] = 12418420.4284705;
  matrix1[1][3] = 13505037.3368630;
  matrix1[1][4] = -17136288.8336113;
  matrix1[1][5] = 16145551.7238631;
  matrix1[1][6] = 14711955.5081414;
  matrix1[1][7] = -12777922.7714290;
  matrix1[1][8] = 5389681.9106146;
  matrix1[1][9] = -5925524.7830532;
  matrix1[2][0] = 13114751.5305993;
  matrix1[2][1] = 18567932.6414752;
  matrix1[2][2] = -13426398.184316;
  matrix1[2][3] = 12925307.803941;
  matrix1[2][4] = -9936273.9578025;
  matrix1[2][5] = 3456476.5539242;
  matrix1[2][6] = 17483065.1569107;
  matrix1[2][7] = -18649327.8548592;
  matrix1[2][8] = 10129083.5908607;
  matrix1[2][9] = 8790915.3469957;
  matrix1[3][0] = -17294983.855060;
  matrix1[3][1] = 1342074.3799662;
  matrix1[3][2] = -10178394.3625579;
  matrix1[3][3] = 16060999.4349788;
  matrix1[3][4] = 20892262.9980347;
  matrix1[3][5] = 15730660.2885195;
  matrix1[3][6] = 18630788.6894032;
  matrix1[3][7] = 17142571.9289402;
  matrix1[3][8] = -17211706.5831613;
  matrix1[3][9] = 21201013.904363;
  matrix1[4][0] = -21259348.775794;
  matrix1[4][1] = 4650956.7043054;
  matrix1[4][2] = 1246599.5546282;
  matrix1[4][3] = -6847534.1905990;
  matrix1[4][4] = 5734671.7307899;
  matrix1[4][5] = 14303528.1190989;
  matrix1[4][6] = 3147341.9800246;
  matrix1[4][7] = 14782007.2857820;
  matrix1[4][8] = -3934544.4374482;
  matrix1[4][9] = 17611440.3273605;
  matrix1[5][0] = 13150357.4906252;
  matrix1[5][1] = -10329208.7288657;
  matrix1[5][2] = 826042.5466928;
  matrix1[5][3] = 5566242.7750181;
  matrix1[5][4] = 5085585.7440329;
  matrix1[5][5] = 16263628.195740;
  matrix1[5][6] = -16566219.2021839;
  matrix1[5][7] = 8215516.6637886;
  matrix1[5][8] = 4502310.2262026;
  matrix1[5][9] = 375080.880343;
  matrix1[6][0] = 3694544.7777475;
  matrix1[6][1] = -18868571.9149722;
  matrix1[6][2] = 4941315.5846323;
  matrix1[6][3] = 14659941.1757162;
  matrix1[6][4] = -13468779.8228098;
  matrix1[6][5] = 14783346.6758818;
  matrix1[6][6] = 12236690.6651564;
  matrix1[6][7] = 2743472.4450160;
  matrix1[6][8] = 12601765.3032449;
  matrix1[6][9] = -7522503.7385828;
  matrix1[7][0] = 12656288.7880656;
  matrix1[7][1] = 17603554.6222439;
  matrix1[7][2] = 3725277.3735880;
  matrix1[7][3] = 17764026.3756817;
  matrix1[7][4] = -6643925.924590;
  matrix1[7][5] = 20361239.6297205;
  matrix1[7][6] = 6132376.8540732;
  matrix1[7][7] = 11786484.2125646;
  matrix1[7][8] = 13999799.5602638;
  matrix1[7][9] = 5247280.3549255;
  matrix1[8][0] = -108468.9282563;
  matrix1[8][1] = 6380447.3917079;
  matrix1[8][2] = -16627156.9750460;
  matrix1[8][3] = 10094767.449346;
  matrix1[8][4] = 18746559.5778436;
  matrix1[8][5] = 2977184.3744667;
  matrix1[8][6] = 5854431.2255495;
  matrix1[8][7] = 14676793.3724778;
  matrix1[8][8] = -10057576.9304280;
  matrix1[8][9] = 4632905.5234953;
  matrix1[9][0] = -13903666.7777110;
  matrix1[9][1] = 17163677.1685032;
  matrix1[9][2] = 18708853.837790;
  matrix1[9][3] = -16195240.1162744;
  matrix1[9][4] = 20790668.7724714;
  matrix1[9][5] = 17945855.2032654;
  matrix1[9][6] = -18401447.2843245;
  matrix1[9][7] = 17331847.8155079;
  matrix1[9][8] = 1724367.3687581;
  matrix1[9][9] = 15852405.5063643;

  S21Matrix object2(object1);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = 1060648.9269141;
  matrix2[0][1] = 13111258.6690684;
  matrix2[0][2] = 14965626.1121514;
  matrix2[0][3] = 17211605.2262267;
  matrix2[0][4] = -7589837.1912895;
  matrix2[0][5] = 20837462.4689637;
  matrix2[0][6] = 5667759.5596447;
  matrix2[0][7] = 5434453.6500901;
  matrix2[0][8] = 10296482.9252318;
  matrix2[0][9] = -15968188.3369038;
  matrix2[1][0] = 6578356.7948861;
  matrix2[1][1] = -16264987.8245067;
  matrix2[1][2] = 12418420.4284705;
  matrix2[1][3] = 13505037.3368630;
  matrix2[1][4] = -17136288.8336113;
  matrix2[1][5] = 16145551.7238631;
  matrix2[1][6] = 14711955.5081414;
  matrix2[1][7] = -12777922.7714290;
  matrix2[1][8] = 5389681.9106146;
  matrix2[1][9] = -5925524.7830532;
  matrix2[2][0] = 13114751.5305993;
  matrix2[2][1] = 18567932.6414752;
  matrix2[2][2] = -13426398.184316;
  matrix2[2][3] = 12925307.803941;
  matrix2[2][4] = -9936273.9578025;
  matrix2[2][5] = 3456476.5539242;
  matrix2[2][6] = 17483065.1569107;
  matrix2[2][7] = -18649327.8548592;
  matrix2[2][8] = 10129083.5908607;
  matrix2[2][9] = 8790915.3469957;
  matrix2[3][0] = -17294983.855060;
  matrix2[3][1] = 1342074.3799662;
  matrix2[3][2] = -10178394.3625579;
  matrix2[3][3] = 16060999.4349788;
  matrix2[3][4] = 20892262.9980347;
  matrix2[3][5] = 15730660.2885195;
  matrix2[3][6] = 18630788.6894032;
  matrix2[3][7] = 17142571.9289402;
  matrix2[3][8] = -17211706.5831613;
  matrix2[3][9] = 21201013.904363;
  matrix2[4][0] = -21259348.775794;
  matrix2[4][1] = 4650956.7043054;
  matrix2[4][2] = 1246599.5546282;
  matrix2[4][3] = -6847534.1905990;
  matrix2[4][4] = 5734671.7307899;
  matrix2[4][5] = 14303528.1190989;
  matrix2[4][6] = 3147341.9800246;
  matrix2[4][7] = 14782007.2857820;
  matrix2[4][8] = -3934544.4374482;
  matrix2[4][9] = 17611440.3273605;
  matrix2[5][0] = 13150357.4906252;
  matrix2[5][1] = -10329208.7288657;
  matrix2[5][2] = 826042.5466928;
  matrix2[5][3] = 5566242.7750181;
  matrix2[5][4] = 5085585.7440329;
  matrix2[5][5] = 16263628.195740;
  matrix2[5][6] = -16566219.2021839;
  matrix2[5][7] = 8215516.6637886;
  matrix2[5][8] = 4502310.2262026;
  matrix2[5][9] = 375080.880343;
  matrix2[6][0] = 3694544.7777475;
  matrix2[6][1] = -18868571.9149722;
  matrix2[6][2] = 4941315.5846323;
  matrix2[6][3] = 14659941.1757162;
  matrix2[6][4] = -13468779.8228098;
  matrix2[6][5] = 14783346.6758818;
  matrix2[6][6] = 12236690.6651564;
  matrix2[6][7] = 2743472.4450160;
  matrix2[6][8] = 12601765.3032449;
  matrix2[6][9] = -7522503.7385828;
  matrix2[7][0] = 12656288.7880656;
  matrix2[7][1] = 17603554.6222439;
  matrix2[7][2] = 3725277.3735880;
  matrix2[7][3] = 17764026.3756817;
  matrix2[7][4] = -6643925.924590;
  matrix2[7][5] = 20361239.6297205;
  matrix2[7][6] = 6132376.8540732;
  matrix2[7][7] = 11786484.2125646;
  matrix2[7][8] = 13999799.5602638;
  matrix2[7][9] = 5247280.3549255;
  matrix2[8][0] = -108468.9282563;
  matrix2[8][1] = 6380447.3917079;
  matrix2[8][2] = -16627156.9750460;
  matrix2[8][3] = 10094767.449346;
  matrix2[8][4] = 18746559.5778436;
  matrix2[8][5] = 2977184.3744667;
  matrix2[8][6] = 5854431.2255495;
  matrix2[8][7] = 14676793.3724778;
  matrix2[8][8] = -10057576.9304280;
  matrix2[8][9] = 4632905.5234953;
  matrix2[9][0] = -13903666.7777110;
  matrix2[9][1] = 17163677.1685032;
  matrix2[9][2] = 18708853.837790;
  matrix2[9][3] = -16195240.1162744;
  matrix2[9][4] = 20790668.7724714;
  matrix2[9][5] = 17945855.2032654;
  matrix2[9][6] = -18401447.2843245;
  matrix2[9][7] = 17331847.8155079;
  matrix2[9][8] = 1724367.3687581;
  matrix2[9][9] = 15852405.50636432;

  EXPECT_TRUE(object1.EqMatrix(object2));
}

TEST(EqMatrix, different_size) {
  S21Matrix object1(5, 5);
  double **matrix1 = object1.GetMatrix();

  matrix1[0][0] = -1783353.3481714;
  matrix1[0][1] = 5949694.3655626;
  matrix1[0][2] = 4887844.8783063;
  matrix1[0][3] = -6267260.9323816;
  matrix1[0][4] = 12596464.1306498;
  matrix1[1][0] = 13190648.8962661;
  matrix1[1][1] = 16780158.6707789;
  matrix1[1][2] = -11318119.7835420;
  matrix1[1][3] = 20537085.3394906;
  matrix1[1][4] = 9726194.4213515;
  matrix1[2][0] = 5537504.4954002;
  matrix1[2][1] = 15883955.5915182;
  matrix1[2][2] = -4513788.4167812;
  matrix1[2][3] = 11325549.9633416;
  matrix1[2][4] = 5035760.1850037;
  matrix1[3][0] = 11380942.6084540;
  matrix1[3][1] = 3949212.5616085;
  matrix1[3][2] = 1886651.5771939;
  matrix1[3][3] = 3207116.8041453;
  matrix1[3][4] = 8146976.3273915;
  matrix1[4][0] = 21443593.8449531;
  matrix1[4][1] = 4144355.4170468;
  matrix1[4][2] = -21414730.9532100;
  matrix1[4][3] = 8106352.3580197;
  matrix1[4][4] = 15627344.5857585;

  S21Matrix object2(4, 5);

  double **matrix2 = object2.GetMatrix();

  matrix2[0][0] = -1783353.3481714;
  matrix2[0][1] = 5949694.3655626;
  matrix2[0][2] = 4887844.8783063;
  matrix2[0][3] = -6267260.9323816;
  matrix2[0][4] = 12596464.1306498;
  matrix2[1][0] = 13190648.8962661;
  matrix2[1][1] = 16780158.6707789;
  matrix2[1][2] = -11318119.7835420;
  matrix2[1][3] = 20537085.3394906;
  matrix2[1][4] = 9726194.4213515;
  matrix2[2][0] = 5537504.4954002;
  matrix2[2][1] = 15883955.5915182;
  matrix2[2][2] = -4513788.4167812;
  matrix2[2][3] = 11325549.9633416;
  matrix2[2][4] = 5035760.1850038;
  matrix2[3][0] = 11380942.6084540;
  matrix2[3][1] = 3949212.5616085;
  matrix2[3][2] = 1886651.5771939;
  matrix2[3][3] = 3207116.8041453;
  matrix2[3][4] = 8146976.3273915;

  EXPECT_FALSE(object1.EqMatrix(object2));
}