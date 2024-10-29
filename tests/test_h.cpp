#include <gtest/gtest.h>
#include "../include/main.h"

TEST(CountTest, HandleCount) {
  char str[101] = "bim bim 1111 bam bam 2222 bom bom";

  int result = Count(str, 0);

  EXPECT_EQ(result, 2);
}