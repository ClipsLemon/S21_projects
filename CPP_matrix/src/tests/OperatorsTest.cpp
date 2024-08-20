#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Operators, copy_operator) {
  S21Matrix matrix(2, 2);
  matrix.GetMatrixEl(0, 0) = 5;
  matrix.GetMatrixEl(0, 1) = 2;
  matrix.GetMatrixEl(1, 0) = 4;
  matrix.GetMatrixEl(1, 1) = 92;

  S21Matrix matrix_cpy;
  matrix_cpy = matrix;
  EXPECT_EQ(matrix.GetMatrixEl(0, 0), matrix_cpy.GetMatrixEl(0, 0));
  EXPECT_EQ(matrix.GetMatrixEl(0, 1), matrix_cpy.GetMatrixEl(0, 1));
  EXPECT_EQ(matrix.GetMatrixEl(1, 0), matrix_cpy.GetMatrixEl(1, 0));
  EXPECT_EQ(matrix.GetMatrixEl(1, 1), matrix_cpy.GetMatrixEl(1, 1));
}

TEST(Operators, move_operator) {
  S21Matrix matrix(2, 2);
  matrix.GetMatrixEl(0, 0) = 5;
  matrix.GetMatrixEl(0, 1) = 2;
  matrix.GetMatrixEl(1, 0) = 4;
  matrix.GetMatrixEl(1, 1) = 92;

  S21Matrix matrix_cpy;
  matrix_cpy = move(matrix);
  EXPECT_EQ(matrix_cpy.GetMatrixEl(0, 0), 5);
  EXPECT_EQ(matrix_cpy.GetMatrixEl(0, 1), 2);
  EXPECT_EQ(matrix_cpy.GetMatrixEl(1, 0), 4);
  EXPECT_EQ(matrix_cpy.GetMatrixEl(1, 1), 92);

  EXPECT_EQ(matrix.GetRow(), DEFAULT_ROWS);
  EXPECT_EQ(matrix.GetCol(), DEFAULT_COLUMNS);
}

TEST(Operators, plus_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = 74968.5646935;
  left_matrix_4.GetMatrixEl(0, 1) = -1168177.7296071;
  left_matrix_4.GetMatrixEl(0, 2) = -3656774.1949352;
  left_matrix_4.GetMatrixEl(0, 3) = -7051115.7719040;
  left_matrix_4.GetMatrixEl(1, 0) = 9246872.5786735;
  left_matrix_4.GetMatrixEl(1, 1) = 7089445.5118437;
  left_matrix_4.GetMatrixEl(1, 2) = 8331077.2807079;
  left_matrix_4.GetMatrixEl(1, 3) = -7362992.8298848;
  left_matrix_4.GetMatrixEl(2, 0) = -4664008.8633516;
  left_matrix_4.GetMatrixEl(2, 1) = 2441702.6605407;
  left_matrix_4.GetMatrixEl(2, 2) = -125750.0418081;
  left_matrix_4.GetMatrixEl(2, 3) = -5725390.0768004;
  left_matrix_4.GetMatrixEl(3, 0) = 7126563.5179251;
  left_matrix_4.GetMatrixEl(3, 1) = 1402959.5967527;
  left_matrix_4.GetMatrixEl(3, 2) = -9248204.3888676;
  left_matrix_4.GetMatrixEl(3, 3) = -8981427.1036168;
  right_matrix_4.GetMatrixEl(0, 0) = -7681647.8916224;
  right_matrix_4.GetMatrixEl(0, 1) = -7511796.5560285;
  right_matrix_4.GetMatrixEl(0, 2) = -5476199.4863146;
  right_matrix_4.GetMatrixEl(0, 3) = 5056713.4437680;
  right_matrix_4.GetMatrixEl(1, 0) = -9971841.8782433;
  right_matrix_4.GetMatrixEl(1, 1) = 6174674.6297323;
  right_matrix_4.GetMatrixEl(1, 2) = 7667458.4944874;
  right_matrix_4.GetMatrixEl(1, 3) = 4435454.3409417;
  right_matrix_4.GetMatrixEl(2, 0) = -5377160.0381750;
  right_matrix_4.GetMatrixEl(2, 1) = 5730160.1055144;
  right_matrix_4.GetMatrixEl(2, 2) = -8683128.2599559;
  right_matrix_4.GetMatrixEl(2, 3) = -2060620.7191698;
  right_matrix_4.GetMatrixEl(3, 0) = -4719457.8861993;
  right_matrix_4.GetMatrixEl(3, 1) = 8052073.6424576;
  right_matrix_4.GetMatrixEl(3, 2) = -9982616.5437028;
  right_matrix_4.GetMatrixEl(3, 3) = 8021029.6287019;
  reference_matrix_4.GetMatrixEl(0, 0) = -7606679.3269289;
  reference_matrix_4.GetMatrixEl(0, 1) = -8679974.2856356;
  reference_matrix_4.GetMatrixEl(0, 2) = -9132973.6812498;
  reference_matrix_4.GetMatrixEl(0, 3) = -1994402.3281360;
  reference_matrix_4.GetMatrixEl(1, 0) = -724969.2995698;
  reference_matrix_4.GetMatrixEl(1, 1) = 13264120.1415760;
  reference_matrix_4.GetMatrixEl(1, 2) = 15998535.7751953;
  reference_matrix_4.GetMatrixEl(1, 3) = -2927538.4889431;
  reference_matrix_4.GetMatrixEl(2, 0) = -10041168.9015266;
  reference_matrix_4.GetMatrixEl(2, 1) = 8171862.7660551;
  reference_matrix_4.GetMatrixEl(2, 2) = -8808878.3017640;
  reference_matrix_4.GetMatrixEl(2, 3) = -7786010.7959702;
  reference_matrix_4.GetMatrixEl(3, 0) = 2407105.6317258;
  reference_matrix_4.GetMatrixEl(3, 1) = 9455033.2392103;
  reference_matrix_4.GetMatrixEl(3, 2) = -19230820.9325704;
  reference_matrix_4.GetMatrixEl(3, 3) = -960397.4749149;

  left_matrix_4 = left_matrix_4 + right_matrix_4;
  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, plus_and_assignment_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = 74968.5646935;
  left_matrix_4.GetMatrixEl(0, 1) = -1168177.7296071;
  left_matrix_4.GetMatrixEl(0, 2) = -3656774.1949352;
  left_matrix_4.GetMatrixEl(0, 3) = -7051115.7719040;
  left_matrix_4.GetMatrixEl(1, 0) = 9246872.5786735;
  left_matrix_4.GetMatrixEl(1, 1) = 7089445.5118437;
  left_matrix_4.GetMatrixEl(1, 2) = 8331077.2807079;
  left_matrix_4.GetMatrixEl(1, 3) = -7362992.8298848;
  left_matrix_4.GetMatrixEl(2, 0) = -4664008.8633516;
  left_matrix_4.GetMatrixEl(2, 1) = 2441702.6605407;
  left_matrix_4.GetMatrixEl(2, 2) = -125750.0418081;
  left_matrix_4.GetMatrixEl(2, 3) = -5725390.0768004;
  left_matrix_4.GetMatrixEl(3, 0) = 7126563.5179251;
  left_matrix_4.GetMatrixEl(3, 1) = 1402959.5967527;
  left_matrix_4.GetMatrixEl(3, 2) = -9248204.3888676;
  left_matrix_4.GetMatrixEl(3, 3) = -8981427.1036168;
  right_matrix_4.GetMatrixEl(0, 0) = -7681647.8916224;
  right_matrix_4.GetMatrixEl(0, 1) = -7511796.5560285;
  right_matrix_4.GetMatrixEl(0, 2) = -5476199.4863146;
  right_matrix_4.GetMatrixEl(0, 3) = 5056713.4437680;
  right_matrix_4.GetMatrixEl(1, 0) = -9971841.8782433;
  right_matrix_4.GetMatrixEl(1, 1) = 6174674.6297323;
  right_matrix_4.GetMatrixEl(1, 2) = 7667458.4944874;
  right_matrix_4.GetMatrixEl(1, 3) = 4435454.3409417;
  right_matrix_4.GetMatrixEl(2, 0) = -5377160.0381750;
  right_matrix_4.GetMatrixEl(2, 1) = 5730160.1055144;
  right_matrix_4.GetMatrixEl(2, 2) = -8683128.2599559;
  right_matrix_4.GetMatrixEl(2, 3) = -2060620.7191698;
  right_matrix_4.GetMatrixEl(3, 0) = -4719457.8861993;
  right_matrix_4.GetMatrixEl(3, 1) = 8052073.6424576;
  right_matrix_4.GetMatrixEl(3, 2) = -9982616.5437028;
  right_matrix_4.GetMatrixEl(3, 3) = 8021029.6287019;
  reference_matrix_4.GetMatrixEl(0, 0) = -7606679.3269289;
  reference_matrix_4.GetMatrixEl(0, 1) = -8679974.2856356;
  reference_matrix_4.GetMatrixEl(0, 2) = -9132973.6812498;
  reference_matrix_4.GetMatrixEl(0, 3) = -1994402.3281360;
  reference_matrix_4.GetMatrixEl(1, 0) = -724969.2995698;
  reference_matrix_4.GetMatrixEl(1, 1) = 13264120.1415760;
  reference_matrix_4.GetMatrixEl(1, 2) = 15998535.7751953;
  reference_matrix_4.GetMatrixEl(1, 3) = -2927538.4889431;
  reference_matrix_4.GetMatrixEl(2, 0) = -10041168.9015266;
  reference_matrix_4.GetMatrixEl(2, 1) = 8171862.7660551;
  reference_matrix_4.GetMatrixEl(2, 2) = -8808878.3017640;
  reference_matrix_4.GetMatrixEl(2, 3) = -7786010.7959702;
  reference_matrix_4.GetMatrixEl(3, 0) = 2407105.6317258;
  reference_matrix_4.GetMatrixEl(3, 1) = 9455033.2392103;
  reference_matrix_4.GetMatrixEl(3, 2) = -19230820.9325704;
  reference_matrix_4.GetMatrixEl(3, 3) = -960397.4749149;

  left_matrix_4 += right_matrix_4;
  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, sub_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);
  left_matrix_4.GetMatrixEl(0, 0) = -4977461.6064825;
  left_matrix_4.GetMatrixEl(0, 1) = -87158.2410691;
  left_matrix_4.GetMatrixEl(0, 2) = 9968395.3608367;
  left_matrix_4.GetMatrixEl(0, 3) = 2310379.7599014;
  left_matrix_4.GetMatrixEl(1, 0) = -8512074.0988491;
  left_matrix_4.GetMatrixEl(1, 1) = 5553644.9251688;
  left_matrix_4.GetMatrixEl(1, 2) = -8925619.8711603;
  left_matrix_4.GetMatrixEl(1, 3) = 3187029.9482091;
  left_matrix_4.GetMatrixEl(2, 0) = 6742444.6428161;
  left_matrix_4.GetMatrixEl(2, 1) = 1236762.9825508;
  left_matrix_4.GetMatrixEl(2, 2) = 3571930.5112857;
  left_matrix_4.GetMatrixEl(2, 3) = 965723.7753057;
  left_matrix_4.GetMatrixEl(3, 0) = 6150828.3811362;
  left_matrix_4.GetMatrixEl(3, 1) = -19893.1135713;
  left_matrix_4.GetMatrixEl(3, 2) = -6472524.2123340;
  left_matrix_4.GetMatrixEl(3, 3) = 434969.1992784;
  right_matrix_4.GetMatrixEl(0, 0) = 7836447.8765724;
  right_matrix_4.GetMatrixEl(0, 1) = -5690012.2519334;
  right_matrix_4.GetMatrixEl(0, 2) = 5386580.7996276;
  right_matrix_4.GetMatrixEl(0, 3) = 256661.2631756;
  right_matrix_4.GetMatrixEl(1, 0) = 9975302.1056068;
  right_matrix_4.GetMatrixEl(1, 1) = 206209.5223548;
  right_matrix_4.GetMatrixEl(1, 2) = 7912108.2924878;
  right_matrix_4.GetMatrixEl(1, 3) = 2655514.1793733;
  right_matrix_4.GetMatrixEl(2, 0) = -1006019.7885972;
  right_matrix_4.GetMatrixEl(2, 1) = -6771664.0664897;
  right_matrix_4.GetMatrixEl(2, 2) = -42190.4528627;
  right_matrix_4.GetMatrixEl(2, 3) = 9764225.7310270;
  right_matrix_4.GetMatrixEl(3, 0) = -4492784.0740354;
  right_matrix_4.GetMatrixEl(3, 1) = -2916657.7126729;
  right_matrix_4.GetMatrixEl(3, 2) = -6427048.5495677;
  right_matrix_4.GetMatrixEl(3, 3) = -4281028.6774713;
  reference_matrix_4.GetMatrixEl(0, 0) = -12813909.4830549;
  reference_matrix_4.GetMatrixEl(0, 1) = 5602854.0108643;
  reference_matrix_4.GetMatrixEl(0, 2) = 4581814.5612091;
  reference_matrix_4.GetMatrixEl(0, 3) = 2053718.4967258;
  reference_matrix_4.GetMatrixEl(1, 0) = -18487376.2044559;
  reference_matrix_4.GetMatrixEl(1, 1) = 5347435.4028140;
  reference_matrix_4.GetMatrixEl(1, 2) = -16837728.1636481;
  reference_matrix_4.GetMatrixEl(1, 3) = 531515.7688358;
  reference_matrix_4.GetMatrixEl(2, 0) = 7748464.4314133;
  reference_matrix_4.GetMatrixEl(2, 1) = 8008427.0490405;
  reference_matrix_4.GetMatrixEl(2, 2) = 3614120.9641484;
  reference_matrix_4.GetMatrixEl(2, 3) = -8798501.9557213;
  reference_matrix_4.GetMatrixEl(3, 0) = 10643612.4551716;
  reference_matrix_4.GetMatrixEl(3, 1) = 2896764.5991016;
  reference_matrix_4.GetMatrixEl(3, 2) = -45475.6627663;
  reference_matrix_4.GetMatrixEl(3, 3) = 4715997.8767497;

  left_matrix_4 = left_matrix_4 - right_matrix_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, sub_and_assignment_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);
  left_matrix_4.GetMatrixEl(0, 0) = -4977461.6064825;
  left_matrix_4.GetMatrixEl(0, 1) = -87158.2410691;
  left_matrix_4.GetMatrixEl(0, 2) = 9968395.3608367;
  left_matrix_4.GetMatrixEl(0, 3) = 2310379.7599014;
  left_matrix_4.GetMatrixEl(1, 0) = -8512074.0988491;
  left_matrix_4.GetMatrixEl(1, 1) = 5553644.9251688;
  left_matrix_4.GetMatrixEl(1, 2) = -8925619.8711603;
  left_matrix_4.GetMatrixEl(1, 3) = 3187029.9482091;
  left_matrix_4.GetMatrixEl(2, 0) = 6742444.6428161;
  left_matrix_4.GetMatrixEl(2, 1) = 1236762.9825508;
  left_matrix_4.GetMatrixEl(2, 2) = 3571930.5112857;
  left_matrix_4.GetMatrixEl(2, 3) = 965723.7753057;
  left_matrix_4.GetMatrixEl(3, 0) = 6150828.3811362;
  left_matrix_4.GetMatrixEl(3, 1) = -19893.1135713;
  left_matrix_4.GetMatrixEl(3, 2) = -6472524.2123340;
  left_matrix_4.GetMatrixEl(3, 3) = 434969.1992784;
  right_matrix_4.GetMatrixEl(0, 0) = 7836447.8765724;
  right_matrix_4.GetMatrixEl(0, 1) = -5690012.2519334;
  right_matrix_4.GetMatrixEl(0, 2) = 5386580.7996276;
  right_matrix_4.GetMatrixEl(0, 3) = 256661.2631756;
  right_matrix_4.GetMatrixEl(1, 0) = 9975302.1056068;
  right_matrix_4.GetMatrixEl(1, 1) = 206209.5223548;
  right_matrix_4.GetMatrixEl(1, 2) = 7912108.2924878;
  right_matrix_4.GetMatrixEl(1, 3) = 2655514.1793733;
  right_matrix_4.GetMatrixEl(2, 0) = -1006019.7885972;
  right_matrix_4.GetMatrixEl(2, 1) = -6771664.0664897;
  right_matrix_4.GetMatrixEl(2, 2) = -42190.4528627;
  right_matrix_4.GetMatrixEl(2, 3) = 9764225.7310270;
  right_matrix_4.GetMatrixEl(3, 0) = -4492784.0740354;
  right_matrix_4.GetMatrixEl(3, 1) = -2916657.7126729;
  right_matrix_4.GetMatrixEl(3, 2) = -6427048.5495677;
  right_matrix_4.GetMatrixEl(3, 3) = -4281028.6774713;
  reference_matrix_4.GetMatrixEl(0, 0) = -12813909.4830549;
  reference_matrix_4.GetMatrixEl(0, 1) = 5602854.0108643;
  reference_matrix_4.GetMatrixEl(0, 2) = 4581814.5612091;
  reference_matrix_4.GetMatrixEl(0, 3) = 2053718.4967258;
  reference_matrix_4.GetMatrixEl(1, 0) = -18487376.2044559;
  reference_matrix_4.GetMatrixEl(1, 1) = 5347435.4028140;
  reference_matrix_4.GetMatrixEl(1, 2) = -16837728.1636481;
  reference_matrix_4.GetMatrixEl(1, 3) = 531515.7688358;
  reference_matrix_4.GetMatrixEl(2, 0) = 7748464.4314133;
  reference_matrix_4.GetMatrixEl(2, 1) = 8008427.0490405;
  reference_matrix_4.GetMatrixEl(2, 2) = 3614120.9641484;
  reference_matrix_4.GetMatrixEl(2, 3) = -8798501.9557213;
  reference_matrix_4.GetMatrixEl(3, 0) = 10643612.4551716;
  reference_matrix_4.GetMatrixEl(3, 1) = 2896764.5991016;
  reference_matrix_4.GetMatrixEl(3, 2) = -45475.6627663;
  reference_matrix_4.GetMatrixEl(3, 3) = 4715997.8767497;

  left_matrix_4 -= right_matrix_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, mul_matrix_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = 0.6960836;
  left_matrix_4.GetMatrixEl(0, 1) = 368.6964211;
  left_matrix_4.GetMatrixEl(0, 2) = -52.7589020;
  left_matrix_4.GetMatrixEl(0, 3) = 881.1890022;
  left_matrix_4.GetMatrixEl(1, 0) = -499.4240049;
  left_matrix_4.GetMatrixEl(1, 1) = -100.4887914;
  left_matrix_4.GetMatrixEl(1, 2) = 579.3207656;
  left_matrix_4.GetMatrixEl(1, 3) = -475.4672587;
  left_matrix_4.GetMatrixEl(2, 0) = -792.8944015;
  left_matrix_4.GetMatrixEl(2, 1) = 857.9824327;
  left_matrix_4.GetMatrixEl(2, 2) = -873.4546720;
  left_matrix_4.GetMatrixEl(2, 3) = -874.0402747;
  left_matrix_4.GetMatrixEl(3, 0) = 255.5616252;
  left_matrix_4.GetMatrixEl(3, 1) = -652.8720369;
  left_matrix_4.GetMatrixEl(3, 2) = -617.7789309;
  left_matrix_4.GetMatrixEl(3, 3) = 802.6457711;
  right_matrix_4.GetMatrixEl(0, 0) = 68.5527298;
  right_matrix_4.GetMatrixEl(0, 1) = -94.1332141;
  right_matrix_4.GetMatrixEl(0, 2) = -57.1595812;
  right_matrix_4.GetMatrixEl(0, 3) = 813.1492258;
  right_matrix_4.GetMatrixEl(1, 0) = -653.6347736;
  right_matrix_4.GetMatrixEl(1, 1) = -284.6179024;
  right_matrix_4.GetMatrixEl(1, 2) = 867.9093824;
  right_matrix_4.GetMatrixEl(1, 3) = -252.7746062;
  right_matrix_4.GetMatrixEl(2, 0) = 396.9943221;
  right_matrix_4.GetMatrixEl(2, 1) = 461.5720687;
  right_matrix_4.GetMatrixEl(2, 2) = 888.6556325;
  right_matrix_4.GetMatrixEl(2, 3) = 157.2216358;
  right_matrix_4.GetMatrixEl(3, 0) = 929.7266466;
  right_matrix_4.GetMatrixEl(3, 1) = -553.5716395;
  right_matrix_4.GetMatrixEl(3, 2) = -336.7214371;
  right_matrix_4.GetMatrixEl(3, 3) = 466.3229963;
  reference_matrix_4.GetMatrixEl(0, 0) = 557374.8282001;
  reference_matrix_4.GetMatrixEl(0, 1) = -617156.4027781;
  reference_matrix_4.GetMatrixEl(0, 2) = -23644.4273214;
  reference_matrix_4.GetMatrixEl(0, 3) = 309992.7821266;
  reference_matrix_4.GetMatrixEl(1, 0) = -180621.4358289;
  reference_matrix_4.GetMatrixEl(1, 1) = 606216.7699489;
  reference_matrix_4.GetMatrixEl(1, 2) = 616248.3820973;
  reference_matrix_4.GetMatrixEl(1, 3) = -511344.7865557;
  reference_matrix_4.GetMatrixEl(2, 0) = -1774537.3078025;
  reference_matrix_4.GetMatrixEl(2, 1) = -88877.8338520;
  reference_matrix_4.GetMatrixEl(2, 2) = 308080.1985743;
  reference_matrix_4.GetMatrixEl(2, 3) = -1406528.6923871;
  reference_matrix_4.GetMatrixEl(3, 0) = 945245.7463607;
  reference_matrix_4.GetMatrixEl(3, 1) = -567709.2020830;
  reference_matrix_4.GetMatrixEl(3, 2) = -1400502.3259105;
  reference_matrix_4.GetMatrixEl(3, 3) = 650003.1765700;

  left_matrix_4 = left_matrix_4 * right_matrix_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, mul_and_assignment_matrix_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix right_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = 0.6960836;
  left_matrix_4.GetMatrixEl(0, 1) = 368.6964211;
  left_matrix_4.GetMatrixEl(0, 2) = -52.7589020;
  left_matrix_4.GetMatrixEl(0, 3) = 881.1890022;
  left_matrix_4.GetMatrixEl(1, 0) = -499.4240049;
  left_matrix_4.GetMatrixEl(1, 1) = -100.4887914;
  left_matrix_4.GetMatrixEl(1, 2) = 579.3207656;
  left_matrix_4.GetMatrixEl(1, 3) = -475.4672587;
  left_matrix_4.GetMatrixEl(2, 0) = -792.8944015;
  left_matrix_4.GetMatrixEl(2, 1) = 857.9824327;
  left_matrix_4.GetMatrixEl(2, 2) = -873.4546720;
  left_matrix_4.GetMatrixEl(2, 3) = -874.0402747;
  left_matrix_4.GetMatrixEl(3, 0) = 255.5616252;
  left_matrix_4.GetMatrixEl(3, 1) = -652.8720369;
  left_matrix_4.GetMatrixEl(3, 2) = -617.7789309;
  left_matrix_4.GetMatrixEl(3, 3) = 802.6457711;
  right_matrix_4.GetMatrixEl(0, 0) = 68.5527298;
  right_matrix_4.GetMatrixEl(0, 1) = -94.1332141;
  right_matrix_4.GetMatrixEl(0, 2) = -57.1595812;
  right_matrix_4.GetMatrixEl(0, 3) = 813.1492258;
  right_matrix_4.GetMatrixEl(1, 0) = -653.6347736;
  right_matrix_4.GetMatrixEl(1, 1) = -284.6179024;
  right_matrix_4.GetMatrixEl(1, 2) = 867.9093824;
  right_matrix_4.GetMatrixEl(1, 3) = -252.7746062;
  right_matrix_4.GetMatrixEl(2, 0) = 396.9943221;
  right_matrix_4.GetMatrixEl(2, 1) = 461.5720687;
  right_matrix_4.GetMatrixEl(2, 2) = 888.6556325;
  right_matrix_4.GetMatrixEl(2, 3) = 157.2216358;
  right_matrix_4.GetMatrixEl(3, 0) = 929.7266466;
  right_matrix_4.GetMatrixEl(3, 1) = -553.5716395;
  right_matrix_4.GetMatrixEl(3, 2) = -336.7214371;
  right_matrix_4.GetMatrixEl(3, 3) = 466.3229963;
  reference_matrix_4.GetMatrixEl(0, 0) = 557374.8282001;
  reference_matrix_4.GetMatrixEl(0, 1) = -617156.4027781;
  reference_matrix_4.GetMatrixEl(0, 2) = -23644.4273214;
  reference_matrix_4.GetMatrixEl(0, 3) = 309992.7821266;
  reference_matrix_4.GetMatrixEl(1, 0) = -180621.4358289;
  reference_matrix_4.GetMatrixEl(1, 1) = 606216.7699489;
  reference_matrix_4.GetMatrixEl(1, 2) = 616248.3820973;
  reference_matrix_4.GetMatrixEl(1, 3) = -511344.7865557;
  reference_matrix_4.GetMatrixEl(2, 0) = -1774537.3078025;
  reference_matrix_4.GetMatrixEl(2, 1) = -88877.8338520;
  reference_matrix_4.GetMatrixEl(2, 2) = 308080.1985743;
  reference_matrix_4.GetMatrixEl(2, 3) = -1406528.6923871;
  reference_matrix_4.GetMatrixEl(3, 0) = 945245.7463607;
  reference_matrix_4.GetMatrixEl(3, 1) = -567709.2020830;
  reference_matrix_4.GetMatrixEl(3, 2) = -1400502.3259105;
  reference_matrix_4.GetMatrixEl(3, 3) = 650003.1765700;

  left_matrix_4 *= right_matrix_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, mul_number_operator_1) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);
  double number_4 = 906;

  left_matrix_4.GetMatrixEl(0, 0) = -224.4491555;
  left_matrix_4.GetMatrixEl(0, 1) = 161.7546953;
  left_matrix_4.GetMatrixEl(0, 2) = -433.6316657;
  left_matrix_4.GetMatrixEl(0, 3) = -897.0038238;
  left_matrix_4.GetMatrixEl(1, 0) = -513.2745290;
  left_matrix_4.GetMatrixEl(1, 1) = -548.3936321;
  left_matrix_4.GetMatrixEl(1, 2) = 729.6466475;
  left_matrix_4.GetMatrixEl(1, 3) = 418.3876700;
  left_matrix_4.GetMatrixEl(2, 0) = -978.6309990;
  left_matrix_4.GetMatrixEl(2, 1) = -997.6896709;
  left_matrix_4.GetMatrixEl(2, 2) = 986.9407383;
  left_matrix_4.GetMatrixEl(2, 3) = 174.7547138;
  left_matrix_4.GetMatrixEl(3, 0) = -973.0769937;
  left_matrix_4.GetMatrixEl(3, 1) = -289.4659202;
  left_matrix_4.GetMatrixEl(3, 2) = 919.1520561;
  left_matrix_4.GetMatrixEl(3, 3) = 472.1598589;
  reference_matrix_4.GetMatrixEl(0, 0) = -203350.9348830;
  reference_matrix_4.GetMatrixEl(0, 1) = 146549.7539418;
  reference_matrix_4.GetMatrixEl(0, 2) = -392870.2891242;
  reference_matrix_4.GetMatrixEl(0, 3) = -812685.4643628;
  reference_matrix_4.GetMatrixEl(1, 0) = -465026.7232740;
  reference_matrix_4.GetMatrixEl(1, 1) = -496844.6306826;
  reference_matrix_4.GetMatrixEl(1, 2) = 661059.8626350;
  reference_matrix_4.GetMatrixEl(1, 3) = 379059.2290200;
  reference_matrix_4.GetMatrixEl(2, 0) = -886639.6850940;
  reference_matrix_4.GetMatrixEl(2, 1) = -903906.8418354;
  reference_matrix_4.GetMatrixEl(2, 2) = 894168.3088998;
  reference_matrix_4.GetMatrixEl(2, 3) = 158327.7707028;
  reference_matrix_4.GetMatrixEl(3, 0) = -881607.7562922;
  reference_matrix_4.GetMatrixEl(3, 1) = -262256.1237012;
  reference_matrix_4.GetMatrixEl(3, 2) = 832751.7628266;
  reference_matrix_4.GetMatrixEl(3, 3) = 427776.8321634;

  left_matrix_4 = left_matrix_4 * number_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, mul_number_operator_2) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);
  double number_4 = 906;

  left_matrix_4.GetMatrixEl(0, 0) = -224.4491555;
  left_matrix_4.GetMatrixEl(0, 1) = 161.7546953;
  left_matrix_4.GetMatrixEl(0, 2) = -433.6316657;
  left_matrix_4.GetMatrixEl(0, 3) = -897.0038238;
  left_matrix_4.GetMatrixEl(1, 0) = -513.2745290;
  left_matrix_4.GetMatrixEl(1, 1) = -548.3936321;
  left_matrix_4.GetMatrixEl(1, 2) = 729.6466475;
  left_matrix_4.GetMatrixEl(1, 3) = 418.3876700;
  left_matrix_4.GetMatrixEl(2, 0) = -978.6309990;
  left_matrix_4.GetMatrixEl(2, 1) = -997.6896709;
  left_matrix_4.GetMatrixEl(2, 2) = 986.9407383;
  left_matrix_4.GetMatrixEl(2, 3) = 174.7547138;
  left_matrix_4.GetMatrixEl(3, 0) = -973.0769937;
  left_matrix_4.GetMatrixEl(3, 1) = -289.4659202;
  left_matrix_4.GetMatrixEl(3, 2) = 919.1520561;
  left_matrix_4.GetMatrixEl(3, 3) = 472.1598589;
  reference_matrix_4.GetMatrixEl(0, 0) = -203350.9348830;
  reference_matrix_4.GetMatrixEl(0, 1) = 146549.7539418;
  reference_matrix_4.GetMatrixEl(0, 2) = -392870.2891242;
  reference_matrix_4.GetMatrixEl(0, 3) = -812685.4643628;
  reference_matrix_4.GetMatrixEl(1, 0) = -465026.7232740;
  reference_matrix_4.GetMatrixEl(1, 1) = -496844.6306826;
  reference_matrix_4.GetMatrixEl(1, 2) = 661059.8626350;
  reference_matrix_4.GetMatrixEl(1, 3) = 379059.2290200;
  reference_matrix_4.GetMatrixEl(2, 0) = -886639.6850940;
  reference_matrix_4.GetMatrixEl(2, 1) = -903906.8418354;
  reference_matrix_4.GetMatrixEl(2, 2) = 894168.3088998;
  reference_matrix_4.GetMatrixEl(2, 3) = 158327.7707028;
  reference_matrix_4.GetMatrixEl(3, 0) = -881607.7562922;
  reference_matrix_4.GetMatrixEl(3, 1) = -262256.1237012;
  reference_matrix_4.GetMatrixEl(3, 2) = 832751.7628266;
  reference_matrix_4.GetMatrixEl(3, 3) = 427776.8321634;

  left_matrix_4 = number_4 * left_matrix_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, mul_assignmber_number_operator) {
  S21Matrix left_matrix_4(4, 4);
  S21Matrix reference_matrix_4(4, 4);
  double number_4 = 906;

  left_matrix_4.GetMatrixEl(0, 0) = -224.4491555;
  left_matrix_4.GetMatrixEl(0, 1) = 161.7546953;
  left_matrix_4.GetMatrixEl(0, 2) = -433.6316657;
  left_matrix_4.GetMatrixEl(0, 3) = -897.0038238;
  left_matrix_4.GetMatrixEl(1, 0) = -513.2745290;
  left_matrix_4.GetMatrixEl(1, 1) = -548.3936321;
  left_matrix_4.GetMatrixEl(1, 2) = 729.6466475;
  left_matrix_4.GetMatrixEl(1, 3) = 418.3876700;
  left_matrix_4.GetMatrixEl(2, 0) = -978.6309990;
  left_matrix_4.GetMatrixEl(2, 1) = -997.6896709;
  left_matrix_4.GetMatrixEl(2, 2) = 986.9407383;
  left_matrix_4.GetMatrixEl(2, 3) = 174.7547138;
  left_matrix_4.GetMatrixEl(3, 0) = -973.0769937;
  left_matrix_4.GetMatrixEl(3, 1) = -289.4659202;
  left_matrix_4.GetMatrixEl(3, 2) = 919.1520561;
  left_matrix_4.GetMatrixEl(3, 3) = 472.1598589;
  reference_matrix_4.GetMatrixEl(0, 0) = -203350.9348830;
  reference_matrix_4.GetMatrixEl(0, 1) = 146549.7539418;
  reference_matrix_4.GetMatrixEl(0, 2) = -392870.2891242;
  reference_matrix_4.GetMatrixEl(0, 3) = -812685.4643628;
  reference_matrix_4.GetMatrixEl(1, 0) = -465026.7232740;
  reference_matrix_4.GetMatrixEl(1, 1) = -496844.6306826;
  reference_matrix_4.GetMatrixEl(1, 2) = 661059.8626350;
  reference_matrix_4.GetMatrixEl(1, 3) = 379059.2290200;
  reference_matrix_4.GetMatrixEl(2, 0) = -886639.6850940;
  reference_matrix_4.GetMatrixEl(2, 1) = -903906.8418354;
  reference_matrix_4.GetMatrixEl(2, 2) = 894168.3088998;
  reference_matrix_4.GetMatrixEl(2, 3) = 158327.7707028;
  reference_matrix_4.GetMatrixEl(3, 0) = -881607.7562922;
  reference_matrix_4.GetMatrixEl(3, 1) = -262256.1237012;
  reference_matrix_4.GetMatrixEl(3, 2) = 832751.7628266;
  reference_matrix_4.GetMatrixEl(3, 3) = 427776.8321634;

  left_matrix_4 *= number_4;

  EXPECT_TRUE(left_matrix_4.EqMatrix(reference_matrix_4));
}

TEST(Operators, equal_operator) {
  S21Matrix left_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = -224.4491555;
  left_matrix_4.GetMatrixEl(0, 1) = 161.7546953;
  left_matrix_4.GetMatrixEl(0, 2) = -433.6316657;
  left_matrix_4.GetMatrixEl(0, 3) = -897.0038238;
  left_matrix_4.GetMatrixEl(1, 0) = -513.2745290;
  left_matrix_4.GetMatrixEl(1, 1) = -548.3936321;
  left_matrix_4.GetMatrixEl(1, 2) = 729.6466475;
  left_matrix_4.GetMatrixEl(1, 3) = 418.3876700;
  left_matrix_4.GetMatrixEl(2, 0) = -978.6309990;
  left_matrix_4.GetMatrixEl(2, 1) = -997.6896709;
  left_matrix_4.GetMatrixEl(2, 2) = 986.9407383;
  left_matrix_4.GetMatrixEl(2, 3) = 174.7547138;
  left_matrix_4.GetMatrixEl(3, 0) = -973.0769937;
  left_matrix_4.GetMatrixEl(3, 1) = -289.4659202;
  left_matrix_4.GetMatrixEl(3, 2) = 919.1520561;
  left_matrix_4.GetMatrixEl(3, 3) = 472.1598589;

  S21Matrix right_matrix_4(left_matrix_4);

  EXPECT_TRUE(right_matrix_4 == left_matrix_4);

  right_matrix_4.GetMatrixEl(0, 0) = 0.;
  EXPECT_FALSE(right_matrix_4 == left_matrix_4);
}

TEST(Operators, index_operator) {
  S21Matrix left_matrix_4(4, 4);

  left_matrix_4.GetMatrixEl(0, 0) = -224.4491555;
  left_matrix_4.GetMatrixEl(0, 1) = 161.7546953;
  left_matrix_4.GetMatrixEl(0, 2) = -433.6316657;
  left_matrix_4.GetMatrixEl(0, 3) = -897.0038238;
  left_matrix_4.GetMatrixEl(1, 0) = -513.2745290;
  left_matrix_4.GetMatrixEl(1, 1) = -548.3936321;
  left_matrix_4.GetMatrixEl(1, 2) = 729.6466475;
  left_matrix_4.GetMatrixEl(1, 3) = 418.3876700;
  left_matrix_4.GetMatrixEl(2, 0) = -978.6309990;
  left_matrix_4.GetMatrixEl(2, 1) = -997.6896709;
  left_matrix_4.GetMatrixEl(2, 2) = 986.9407383;
  left_matrix_4.GetMatrixEl(2, 3) = 174.7547138;
  left_matrix_4.GetMatrixEl(3, 0) = -973.0769937;
  left_matrix_4.GetMatrixEl(3, 1) = -289.4659202;
  left_matrix_4.GetMatrixEl(3, 2) = 919.1520561;
  left_matrix_4.GetMatrixEl(3, 3) = 472.1598589;

  EXPECT_FLOAT_EQ(left_matrix_4(0, 3), -897.0038238);

  EXPECT_THROW(
      try {
        left_matrix_4(left_matrix_4.GetRow() + 1, left_matrix_4.GetCol() + 1);
      } catch (const out_of_range &e) {
        EXPECT_STREQ("Index is outside the matrix.", e.what());
        throw;
      },
      out_of_range);
}