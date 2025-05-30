; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --version 5
; RUN: opt -S --passes=slp-vectorizer -mtriple=x86_64-unknown-linux < %s | FileCheck %s

define i8 @test() {
; CHECK-LABEL: define i8 @test() {
; CHECK-NEXT:  [[ENTRY:.*:]]
; CHECK-NEXT:    [[SUB_I_I79_PEEL_I:%.*]] = sub i16 0, 1
; CHECK-NEXT:    [[TMP0:%.*]] = insertelement <2 x i16> <i16 poison, i16 0>, i16 [[SUB_I_I79_PEEL_I]], i32 0
; CHECK-NEXT:    [[TMP2:%.*]] = zext <2 x i16> [[TMP0]] to <2 x i32>
; CHECK-NEXT:    [[TMP1:%.*]] = icmp slt <2 x i32> zeroinitializer, [[TMP2]]
; CHECK-NEXT:    [[TMP3:%.*]] = zext <2 x i1> [[TMP1]] to <2 x i16>
; CHECK-NEXT:    [[TMP4:%.*]] = or <2 x i16> [[TMP3]], [[TMP0]]
; CHECK-NEXT:    [[TMP6:%.*]] = icmp eq <2 x i16> [[TMP4]], [[TMP0]]
; CHECK-NEXT:    [[TMP5:%.*]] = extractelement <2 x i1> [[TMP1]], i32 0
; CHECK-NEXT:    [[CONV13_I89_PEEL_I:%.*]] = zext i1 [[TMP5]] to i8
; CHECK-NEXT:    ret i8 [[CONV13_I89_PEEL_I]]
;
entry:
  %conv4.i.i = zext i16 0 to i32
  %conv7.i.i = sext i16 0 to i32
  %cmp8.i.i = icmp slt i32 %conv7.i.i, %conv4.i.i
  %conv9.i.i = zext i1 %cmp8.i.i to i32
  %or10.i.i = or i32 %conv9.i.i, %conv4.i.i
  %cmp11.i.i = icmp eq i32 %or10.i.i, %conv4.i.i
  %sub.i.i79.peel.i = sub i16 0, 1
  %xor5.i81.peel.i = zext i16 %sub.i.i79.peel.i to i32
  %conv7.i84.peel.i = sext i16 0 to i32
  %cmp8.i85.peel.i = icmp slt i32 %conv7.i84.peel.i, %xor5.i81.peel.i
  %conv9.i86.peel.i = zext i1 %cmp8.i85.peel.i to i32
  %or10.i87.peel.i = or i32 %conv9.i86.peel.i, %xor5.i81.peel.i
  %cmp11.i88.peel.i = icmp eq i32 %or10.i87.peel.i, %xor5.i81.peel.i
  %conv13.i89.peel.i = zext i1 %cmp8.i85.peel.i to i8
  ret i8 %conv13.i89.peel.i
}
