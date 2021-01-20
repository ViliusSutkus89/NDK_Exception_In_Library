package com.viliussutkus89.exceptioner;

import android.content.Context;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.platform.app.InstrumentationRegistry;

import com.getkeepsafe.relinker.ReLinker;

import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.assertTrue;

@RunWith(AndroidJUnit4.class)
public class ExceptionInstrumentedTest {
  @BeforeClass
  public static void extractPDFs() {
    final Context ctx = InstrumentationRegistry.getInstrumentation().getTargetContext();
    ReLinker.loadLibrary(ctx, "thrower");
    ReLinker.loadLibrary(ctx, "catcher");
  }

  @Test
  public void throwRuntimeErrorTest() {
    assertTrue(throwRuntimeError());
  }

  @Test
  public void throwRuntimeErrorInLibTest() {
    assertTrue(throwRuntimeErrorInLib());
  }

  @Test
  public void throwAndCatchRuntimeErrorInLibTest() {
    assertTrue(throwAndCatchRuntimeErrorInLib());
  }

  @Test
  public void throwExtendedTest() {
    assertTrue(throwExtended());
  }

  @Test
  public void throwExtendedInLibTest() {
    assertTrue(throwExtendedInLib());
  }

  @Test
  public void throwAndCatchExtendedInLibTest() {
    assertTrue(throwAndCatchExtendedInLib());
  }

  private static native boolean throwRuntimeError();
  private static native boolean throwRuntimeErrorInLib();
  private static native boolean throwAndCatchRuntimeErrorInLib();

  private static native boolean throwExtended();
  private static native boolean throwExtendedInLib();
  private static native boolean throwAndCatchExtendedInLib();

}