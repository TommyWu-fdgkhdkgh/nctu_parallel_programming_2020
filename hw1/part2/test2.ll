; ModuleID = './test2.cpp'
source_filename = "./test2.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%"class.std::basic_ostream" = type { i32 (...)**, %"class.std::basic_ios" }
%"class.std::basic_ios" = type { %"class.std::ios_base", %"class.std::basic_ostream"*, i8, i8, %"class.std::basic_streambuf"*, %"class.std::ctype"*, %"class.std::num_put"*, %"class.std::num_get"* }
%"class.std::ios_base" = type { i32 (...)**, i64, i64, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i64 }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i64, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type <{ i32 (...)**, i32, [4 x i8] }>
%"class.std::basic_streambuf" = type { i32 (...)**, i8*, i8*, i8*, i8*, i8*, i8*, %"class.std::locale" }
%"class.std::ctype" = type <{ %"class.std::locale::facet.base", [4 x i8], %struct.__locale_struct*, i8, [7 x i8], i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8, [6 x i8] }>
%"class.std::locale::facet.base" = type <{ i32 (...)**, i32 }>
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%"class.std::num_put" = type { %"class.std::locale::facet.base", [4 x i8] }
%"class.std::num_get" = type { %"class.std::locale::facet.base", [4 x i8] }
%struct.timespec = type { i64, i64 }

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@_ZSt4cout = external dso_local global %"class.std::basic_ostream", align 8
@.str = private unnamed_addr constant [48 x i8] c"Elapsed execution time of the loop in test2():\0A\00", align 1
@.str.1 = private unnamed_addr constant [9 x i8] c"sec (N: \00", align 1
@.str.2 = private unnamed_addr constant [6 x i8] c", I: \00", align 1
@.str.3 = private unnamed_addr constant [3 x i8] c")\0A\00", align 1
@.str.4 = private unnamed_addr constant [7 x i8] c"r == 0\00", align 1
@.str.5 = private unnamed_addr constant [13 x i8] c"./fasttime.h\00", align 1
@__PRETTY_FUNCTION__._ZL7gettimev = private unnamed_addr constant [21 x i8] c"fasttime_t gettime()\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_test2.cpp, i8* null }]

declare dso_local void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) unnamed_addr #0

; Function Attrs: nounwind
declare dso_local void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) unnamed_addr #1

; Function Attrs: nofree nounwind
declare dso_local i32 @__cxa_atexit(void (i8*)*, i8*, i8*) local_unnamed_addr #2

; Function Attrs: uwtable
define dso_local void @_Z5test2PfS_S_i(float* noalias %a, float* noalias %b, float* noalias nocapture %c, i32 %N) local_unnamed_addr #3 {
entry:
  %retval.i57 = alloca %struct.timespec, align 8
  %retval.i = alloca %struct.timespec, align 8
  %cmp = icmp eq i32 %N, 1024
  tail call void @llvm.assume(i1 %cmp)
  %ptrint = ptrtoint float* %a to i64
  %maskedptr = and i64 %ptrint, 15
  %maskcond = icmp eq i64 %maskedptr, 0
  tail call void @llvm.assume(i1 %maskcond)
  %ptrint1 = ptrtoint float* %b to i64
  %maskedptr2 = and i64 %ptrint1, 15
  %maskcond3 = icmp eq i64 %maskedptr2, 0
  tail call void @llvm.assume(i1 %maskcond3)
  %0 = bitcast %struct.timespec* %retval.i to i8*
  call void @llvm.lifetime.start.p0i8(i64 16, i8* nonnull %0)
  %call.i = call i32 @clock_gettime(i32 1, %struct.timespec* nonnull %retval.i) #7
  %cmp.i = icmp eq i32 %call.i, 0
  br i1 %cmp.i, label %_ZL7gettimev.exit, label %cond.false.i

cond.false.i:                                     ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.4, i64 0, i64 0), i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.5, i64 0, i64 0), i32 75, i8* getelementptr inbounds ([21 x i8], [21 x i8]* @__PRETTY_FUNCTION__._ZL7gettimev, i64 0, i64 0)) #8
  unreachable

_ZL7gettimev.exit:                                ; preds = %entry
  %.fca.0.gep.i = getelementptr inbounds %struct.timespec, %struct.timespec* %retval.i, i64 0, i32 0
  %.fca.0.load.i = load i64, i64* %.fca.0.gep.i, align 8
  %1 = getelementptr inbounds %struct.timespec, %struct.timespec* %retval.i, i64 0, i32 1
  %.fca.1.load.i = load i64, i64* %1, align 8
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %0)
  br label %for.cond5.preheader

for.cond5.preheader:                              ; preds = %for.cond.cleanup7, %_ZL7gettimev.exit
  %i.075 = phi i32 [ 0, %_ZL7gettimev.exit ], [ %inc21, %for.cond.cleanup7 ]
  br label %for.body8

for.cond.cleanup:                                 ; preds = %for.cond.cleanup7
  %2 = bitcast %struct.timespec* %retval.i57 to i8*
  call void @llvm.lifetime.start.p0i8(i64 16, i8* nonnull %2)
  %call.i58 = call i32 @clock_gettime(i32 1, %struct.timespec* nonnull %retval.i57) #7
  %cmp.i59 = icmp eq i32 %call.i58, 0
  br i1 %cmp.i59, label %_ZL7gettimev.exit66, label %cond.false.i60

cond.false.i60:                                   ; preds = %for.cond.cleanup
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.4, i64 0, i64 0), i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.5, i64 0, i64 0), i32 75, i8* getelementptr inbounds ([21 x i8], [21 x i8]* @__PRETTY_FUNCTION__._ZL7gettimev, i64 0, i64 0)) #8
  unreachable

_ZL7gettimev.exit66:                              ; preds = %for.cond.cleanup
  %.fca.0.gep.i61 = getelementptr inbounds %struct.timespec, %struct.timespec* %retval.i57, i64 0, i32 0
  %.fca.0.load.i62 = load i64, i64* %.fca.0.gep.i61, align 8
  %3 = getelementptr inbounds %struct.timespec, %struct.timespec* %retval.i57, i64 0, i32 1
  %.fca.1.load.i64 = load i64, i64* %3, align 8
  call void @llvm.lifetime.end.p0i8(i64 16, i8* nonnull %2)
  %sub.i = sub nsw i64 %.fca.0.load.i62, %.fca.0.load.i
  %conv.i = sitofp i64 %sub.i to double
  %sub3.i = sub nsw i64 %.fca.1.load.i64, %.fca.1.load.i
  %conv4.i = sitofp i64 %sub3.i to double
  %mul.i = fmul double %conv4.i, 1.000000e-09
  %add.i = fadd double %mul.i, %conv.i
  %call1.i = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) @_ZSt4cout, i8* nonnull getelementptr inbounds ([48 x i8], [48 x i8]* @.str, i64 0, i64 0), i64 47)
  %call.i67 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIdEERSoT_(%"class.std::basic_ostream"* nonnull @_ZSt4cout, double %add.i)
  %call1.i69 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %call.i67, i8* nonnull getelementptr inbounds ([9 x i8], [9 x i8]* @.str.1, i64 0, i64 0), i64 8)
  %call29 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* nonnull %call.i67, i32 1024)
  %call1.i71 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %call29, i8* nonnull getelementptr inbounds ([6 x i8], [6 x i8]* @.str.2, i64 0, i64 0), i64 5)
  %call31 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"* nonnull %call29, i32 20000000)
  %call1.i73 = call dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* nonnull dereferenceable(272) %call31, i8* nonnull getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i64 0, i64 0), i64 2)
  ret void

for.cond.cleanup7:                                ; preds = %for.inc.1
  %inc21 = add nuw nsw i32 %i.075, 1
  %exitcond77 = icmp eq i32 %inc21, 20000000
  br i1 %exitcond77, label %for.cond.cleanup, label %for.cond5.preheader

for.body8:                                        ; preds = %for.inc.1, %for.cond5.preheader
  %indvars.iv = phi i64 [ 0, %for.cond5.preheader ], [ %indvars.iv.next.1, %for.inc.1 ]
  %arrayidx = getelementptr inbounds float, float* %a, i64 %indvars.iv
  %4 = bitcast float* %arrayidx to i32*
  %5 = load i32, i32* %4, align 8, !tbaa !2
  %arrayidx10 = getelementptr inbounds float, float* %c, i64 %indvars.iv
  %6 = bitcast float* %arrayidx10 to i32*
  store i32 %5, i32* %6, align 4, !tbaa !2
  %arrayidx12 = getelementptr inbounds float, float* %b, i64 %indvars.iv
  %7 = load float, float* %arrayidx12, align 8, !tbaa !2
  %.cast = bitcast i32 %5 to float
  %cmp15 = fcmp ogt float %7, %.cast
  br i1 %cmp15, label %if.then, label %for.inc

if.then:                                          ; preds = %for.body8
  store float %7, float* %arrayidx10, align 4, !tbaa !2
  br label %for.inc

for.inc:                                          ; preds = %for.body8, %if.then
  %indvars.iv.next = or i64 %indvars.iv, 1
  %arrayidx.1 = getelementptr inbounds float, float* %a, i64 %indvars.iv.next
  %8 = bitcast float* %arrayidx.1 to i32*
  %9 = load i32, i32* %8, align 4, !tbaa !2
  %arrayidx10.1 = getelementptr inbounds float, float* %c, i64 %indvars.iv.next
  %10 = bitcast float* %arrayidx10.1 to i32*
  store i32 %9, i32* %10, align 4, !tbaa !2
  %arrayidx12.1 = getelementptr inbounds float, float* %b, i64 %indvars.iv.next
  %11 = load float, float* %arrayidx12.1, align 4, !tbaa !2
  %.cast.1 = bitcast i32 %9 to float
  %cmp15.1 = fcmp ogt float %11, %.cast.1
  br i1 %cmp15.1, label %if.then.1, label %for.inc.1

if.then.1:                                        ; preds = %for.inc
  store float %11, float* %arrayidx10.1, align 4, !tbaa !2
  br label %for.inc.1

for.inc.1:                                        ; preds = %if.then.1, %for.inc
  %indvars.iv.next.1 = add nuw nsw i64 %indvars.iv, 2
  %exitcond.1 = icmp eq i64 %indvars.iv.next.1, 1024
  br i1 %exitcond.1, label %for.cond.cleanup7, label %for.body8
}

; Function Attrs: nounwind willreturn
declare void @llvm.assume(i1) #4

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSolsEi(%"class.std::basic_ostream"*, i32) local_unnamed_addr #0

; Function Attrs: nounwind
declare dso_local i32 @clock_gettime(i32, %struct.timespec*) local_unnamed_addr #1

; Function Attrs: noreturn nounwind
declare dso_local void @__assert_fail(i8*, i8*, i32, i8*) local_unnamed_addr #5

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(%"class.std::basic_ostream"* dereferenceable(272), i8*, i64) local_unnamed_addr #0

declare dso_local dereferenceable(272) %"class.std::basic_ostream"* @_ZNSo9_M_insertIdEERSoT_(%"class.std::basic_ostream"*, double) local_unnamed_addr #0

; Function Attrs: uwtable
define internal void @_GLOBAL__sub_I_test2.cpp() #3 section ".text.startup" {
entry:
  tail call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* nonnull @_ZStL8__ioinit)
  %0 = tail call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init", %"class.std::ios_base::Init"* @_ZStL8__ioinit, i64 0, i32 0), i8* nonnull @__dso_handle) #7
  ret void
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #6

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #6

attributes #0 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nofree nounwind }
attributes #3 = { uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind willreturn }
attributes #5 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { argmemonly nounwind willreturn }
attributes #7 = { nounwind }
attributes #8 = { noreturn nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0 "}
!2 = !{!3, !3, i64 0}
!3 = !{!"float", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C++ TBAA"}
